#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <stdexcept>
#include <thread>
#include <vector>

class ThreadPool {
public:
  ThreadPool(size_t);
  template <class F, class... Args>
  auto enqueue(F &&f, Args &&... args)
      -> std::future<typename std::result_of<F(Args...)>::type>;
  ~ThreadPool();

private:
  // need to keep track of threads so we can join them
  std::vector<std::thread> workers;
  // the task queue
  std::queue<std::function<void()>> tasks;

  // synchronization
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads) : stop(false) {
  for (size_t i = 0; i < threads; ++i)
    // 创建多个工作线程 workers，每一个线程的主任务都是无限循环等待 this->condition 的通知到达后运行对应的task
    workers.emplace_back([this] {
      for (;;) {
        std::function<void()> task;
        {
          std::unique_lock<std::mutex> lock(this->queue_mutex);
          // 等待消息通知后拿到任务来运行
          this->condition.wait(lock, 
            [this] { return this->stop || !this->tasks.empty(); });
          if (this->stop && this->tasks.empty())
            return; // 收到 stop 命令且 tasks 执行完成后才退出
          task = std::move(this->tasks.front());
          this->tasks.pop();
        }

        task(); // 运行线程的主要任务
      }
    });
}

// add new work item to the pool
template <class F, class... Args>
auto ThreadPool::enqueue(F &&f, Args &&... args)
    -> std::future<typename std::result_of<F(Args...)>::type> {
  using return_type = typename std::result_of<F(Args...)>::type;

  auto task = std::make_shared<std::packaged_task<return_type()>>(
      std::bind(std::forward<F>(f), std::forward<Args>(args)...));

  std::future<return_type> res = task->get_future();
  {
    std::unique_lock<std::mutex> lock(queue_mutex);

    // don't allow enqueueing after stopping the pool
    if (stop)
      throw std::runtime_error("enqueue on stopped ThreadPool");

    tasks.emplace([task](){ (*task)(); }); //增加tasks任务，使用 lambda 的形式运行task() -> 函数bind参数后的函数指针
  }
  condition.notify_one();
  return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex);
    stop = true;
  }
  condition.notify_all();
  for (std::thread &worker : workers)
    worker.join();
}

#endif
