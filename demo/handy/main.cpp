#include <handy/handy.h>
using namespace handy;
/*
1. 编译：
g++ main.cpp -o main.o -std=c++11 -I../../gitee/handy/ -L../../gitee/handy/ -lhandy

2. 运行测试：
sudo ./main.o # 运行服务器
nc 127.0.0.1 99 # 启动客户端链接服务器，之后可以输入命令
curl http://127.0.0.1:99 # 也可以模拟http数据
*/

int main(int argc, const char* argv[]) {
  EventBase base;
  Signal::signal(SIGINT, [&] { base.exit(); });
  TcpServerPtr svr = TcpServer::startServer(&base, "127.0.0.1", 99);
  exitif(svr == NULL, "start tcp server failed");
  svr->onConnRead([](const TcpConnPtr& con) { con->send(con->getInput()); });
  base.loop();
}