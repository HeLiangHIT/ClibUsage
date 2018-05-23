# C-libUsage
一些开源库的使用方法介绍和实例

常用依赖包：
```sh
brew install glog # 安装到了 /usr/local/Cellar/glog/0.3.5_3
brew install libevent # 安装到了 /usr/local/Cellar/libevent/2.1.8
brew install gcc make cmake
brew install boost # 安装到了 /usr/local/Cellar/boost/1.66.0
brew install autoconf # /usr/local/Cellar/autoconf/2.69
brew install automake # /usr/local/Cellar/automake/1.16.1
brew install pkg-config # /usr/local/Cellar/pkg-config/0.29.2
# 将 gtest 安装到home目录下
git clone https://github.com/google/googletest.git
cd googletest/googletest && mkdir bld && cd bld
cmake .. && make -j
cp -a ../include/gtest ~/include
cp -a *.a ~/lib
cd ../../googlemock && mkdir bld && cd bld
cmake .. && make -j
cp -a ../include/gmock ~/include
cp -a *.a ~/lib
# 将 protobuf 安装到home目录下
git clone git@github.com:google/protobuf.git
cd protobuf && ./autogen.sh && mkdir bld && cd bld 
../configure --prefix=/Users/heliang/
sudo make -j && make install
```

# 网络

## HTTP客户端 cpprestexample
地址：https://github.com/shaovoon/cpprestexample 
例子： https://www.codeproject.com/Articles/1244632/Making-HTTP-REST-Request-in-Cplusplus


## 基于C++11 的高性能网络服务器 evpp[编译不过]
项目简介： evpp 是一个基于 libevent 开发的现代化 C++11 高性能网络服务器，自带 TCP/UDP/HTTP 等协议的异步非阻塞式的服务器和客户端库，具有如下特性：
现代版的 C++11接口
非阻塞异步接口都是 C++11 的 functional/bind 形式的回调仿函数（不是 libevent 中的C风格的函数指针）
CPU 多核友好和线程安全
非阻塞纯异步多线程 TCP 服务器/客户端
非阻塞纯异步多线程 HTTP 服务器/客户端
非阻塞纯异步多线程 UDP 服务器
支持多进程模式
优秀的跨平台特性和高性能（继承自 libevent 的优点）
已经经过详尽的测试，并已经用于生产环境，每天承载数万亿次的网络通信
非常容易安装和集成，evpp 能够很容易就打包出 deb/rpm/tar.gz 等格式的安装包
项目地址：
https://gitee.com/zieckey/evpp

读后感：看起来挺好用的，但是编译过不了，等编译没问题了再看吧。

### 代码下载和安装
```sh
git clone https://github.com/Qihoo360/evpp
cd evpp && git submodule update --init --recursive
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j4 && make test #编译有错放弃！开源工程做得不够兼容。
# server_status.h:28:9: error: multiple conversions from switch condition type 'const std::atomic<Status>' to an integral or enumeration type
```


## 简洁易用的 C++11 网络库 handy [亲测可用]
项目简介： 本项目是一个简洁易用的 C++11网络库，主要特性如下所示：
支持单机千万并发连接
多平台支持
支持优雅退出
高性能
支持半同步半异步处理
openssl 支持
protobuf 支持
udp 支持
项目地址： https://gitee.com/yedf/handy
拉取过来： https://gitee.com/heliangHIT/handy

编译安装：`make` (不建议安装 `make install`， 当成库用就可以了)
编码测试（含命令）：[./demo/handy/main.cpp](./demo/handy/main.cpp)
用后感：使用方法挺简单的，用起来很方便很不错。

# 工具
## json库
JSON for Modern C++ 是一个由德国大牛 nlohmann 编写的在 C++ 下使用的 JSON 库。
具有以下特点
直观的语法
整个代码由一个头文件组成 json.hpp，没有子项目，没有依赖关系，没有复杂的构建系统，使用起来非常方便
使用 C++ 11 标准编写
使用 json 像使用 STL 容器一样
STL 和 json 容器之间可以相互转换
严谨的测试：所有类都经过严格的单元测试，覆盖了 100％ 的代码，包括所有特殊的行为。此外，还检查了 Valgrind 是否有内存泄漏。为了保持高质量，该项目遵循核心基础设施倡议(CII)的最佳实践
项目地址： https://github.com/nlohmann/json
fork项目地址： https://github.com/HeLiangHIT/json

编译安装：这个工程的使用只需要一个头文件，无需编译和安装！非常简单，下面的命令是编译测试代码而已。
```
mkdir build && cd build
cmake .. && cmake --build .
```
还有很多高级的用法参考readme。
编码测试（含命令）：[./demo/json/main.cpp](./demo/json/main.cpp)
用后感：没有比这个更好用的c++json库了！只需要头文件就可以了！相比JSON官方推荐的第三方库JsonCpp这个使用体验好多了--无需安装和链接等麻烦的操作！



## cpu_features 一个CPU功能分析工具
项目地址： https://github.com/google/cpu_features

+ Simple to use. See the snippets below for examples.
+ Extensible. Easy to add missing features or architectures.
+ Compatible with old compilers and available on many architectures so it can be used widely. To ensure that cpu_features works on as many platforms as possible, we implemented it in a highly portable version of C: C99.
+ Sandbox-compatible. The library uses a variety of strategies to cope with sandboxed environments or when cpuid is unavailable. This is useful when running integration tests in hermetic environments.
+ Thread safe, no memory allocation, and raises no exceptions. cpu_features is suitable for implementing fundamental libc functions like malloc, memcpy, and memcmp.
+ Unit tested.

编译：
```sh
mkdir build && cd build
cmake .. && make -j
./build/list_cpu_features # 列出本机CPU参数
"arch           : x86
brand           :  Intel(R) Xeon(R) CPU E5-1650 0 @ 3.20GHz
family          :   6 (0x06)
model           :  45 (0x2D)
stepping        :   7 (0x07)
uarch           : INTEL_SNB
flags           : aes,avx,cx16,smx,sse4_1,sse4_2,ssse3"
```
使用：直接使用前面编译的苦，或者参考官方说明使用如下方法编译代码到项目中
1- Download cpu_features and copy it in a sub-directory in your project. or add cpu_features as a git-submodule in your project
2- You can then use the cmake command add_subdirectory() to include cpu_features directly and use the cpu_features target in your project.
3- Add the cpu_features target to the target_link_libraries() section of your executable or of your library.

编译测试： [./demo/cpu_features/main.c](./demo/cpu_features/main.c)

## simplebinstream 最小二进制流
基于C ++文件流的基于头文件的最小二进制流，其中可以为您的自定义类型重载流操作符。
源码： https://github.com/shaovoon/simplebinstream
用法： https://www.codeproject.com/Tips/808776/Cplusplus-Simplistic-Binary-Streams
核心语法参考： https://www.codeproject.com/Tips/1244491/Cplusplus-Compile-time-Conditional-Types


## 微信c/c++协程库
项目地址： https://github.com/Tencent/libco
libco通过仅有的几个函数接口 co_create/co_resume/co_yield 再配合 co_poll，可以支持同步或者异步的写法，如线程库一样轻松。同时库里面提供了socket族函数的hook，使得后台逻辑服务几乎不用修改逻辑代码就可以完成异步化改造。
> 和libprocess比貌似还差一些，编写代码并不怎么方便。项目下面有例子，但是写法可读性并不强，有点怀疑代码的稳定性和可靠性。


# C图形界面开发库 LCUI
项目介绍： https://www.oschina.net/p/lcui
官网： http://www.lcui.org/
GitHub地址： https://github.com/lc-soft/LCUI
LCUI 是一个用 C 语言编写的图形界面开发库，支持使用 CSS 和 XML 描述界面布局和样式，可用于构建简单的桌面应用程序。
此项目主要由作者利用闲余时间进行开发和维护，项目的活跃度通常会受到各种因素的影响，大多数时间内都处于低活跃度状态。
写出来的界面相比VS很优美！

测试安装和测试：
```sh
git clone https://github.com/lc-soft/LCUI.git
cd LCUI && ./autogen.sh && ./configure --prefix=/Users/heliang/ # 会自己新建lib文件夹
make -j && make install

cd test && make
./hellowrold
```

测试结果： 在mac上无法编译，因为字体无法读取，开发者应该只是在win上测试了。





