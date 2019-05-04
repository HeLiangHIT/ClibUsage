# C-libUsage
一些开源库的使用方法介绍和实例

常用依赖包：
```
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

# only hpp

## gzip 压缩解压 only hpp
https://github.com/mapbox/gzip-hpp
纯 hpp 的 gzip 库文件，非常简洁易用。

## 信号和槽绑定库 only hpp
https://github.com/fr00b0/nod
用于信号和槽的使用，仅头文件。线程安全~
参考 [ClibUsage/github/nod/nod.hpp](ClibUsage/github/nod/nod.hpp)


## ThreadPool only hpp
https://github.com/progschj/ThreadPool
用于快速创建线程池


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

# 游戏
## 新一代 C ++ 游戏开发框架 bs :: framework
bs::framework 是一个新一代 C ++ 游戏开发框架，专注于现代技术、高质量设计和高性能，旨在为开发实时图形应用程序（游戏、引擎或工具）提供统一的基础。

bs::framework 提供了从音频、动画、GUI、输入、物理、渲染到脚本系统等图形应用开发所需的一切。它还内置了对30多种图像、mesh 和音频格式的支持，以及应用广泛的数学库、RTTI（run-time type information）、CPU / GPU分析、SIMD 指令 API 和更多。跨 Windows、Linux 和 MacOS 平台。

下载地址： https://gitee.com/mirrors/bs-framework 或者 https://github.com/GameFoundry/bsf




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

## uftrace 跟踪和分析 C/C++ 程序执行情况[简单实用]
uftrace 用于跟踪和分析 C/C++ 编写的程序的执行情况，它受到 Linux 内核的 ftrace 框架的启发（特别是 function graph tracer），支持 userspace 程序。uftrace 还支持各种类型的命令和过滤器，以帮助分析程序执行和性能。
功能特性
+ 跟踪可执行文件中的每个函数并显示持续时间，还可以跟踪外部库调用入口和出口，并且不能跟踪库调用中的内部函数调用，除非库本身已启用分析构建。
+ 可以在函数层面显示详细的执行流程，并报告哪个函数的开销最高，它还显示与执行环境有关的各种信息。
+ 在追踪时，可以设置过滤器以排除或包含特定的函数。另外，它可以保存和显示函数参数并返回值。
+ 它支持多进程/多线程应用程序， 如果系统启用内核中的 function graph tracer，并使用 root 权限，可以跟踪内核函数（使用 -k 参数）

地址： https://github.com/namhyung/uftrace
看官网就知道很实用！安装和使用都很简单！

```
make; make install; # 编译安装
# 编译程序增加参数 -pg (or -finstrument-functions) 以保证产生各个函数的分析代码
uftrace tests/t-abc # 查看函数调用代码
uftrace record tests/t-abc # 记录运行过程
sudo uftrace -k tests/t-hello # 允许跟踪系统调用栈
uftrace report #查看哪些函数最费时间
uftrace graph  main # 显示指定函数的调用关系图
uftrace dump --chrome #浏览器查看结果
```




## 腾讯c/c++协程库
项目地址： https://github.com/Tencent/libco
libco通过仅有的几个函数接口 co_create/co_resume/co_yield 再配合 co_poll，可以支持同步或者异步的写法，如线程库一样轻松。同时库里面提供了socket族函数的hook，使得后台逻辑服务几乎不用修改逻辑代码就可以完成异步化改造。
> 和libprocess比貌似还差一些，编写代码并不怎么方便。项目下面有例子，但是写法可读性并不强，有点怀疑代码的稳定性和可靠性。

> 别人评价： 以部分正确的方式HOOK了网络io相关的syscall，可以少改甚至不改代码的兼容大多数第三方库；特点：没有完整生态。 这一层次的协程库，但是hook的不够完善，未能完全模拟syscall的行为，只能兼容行为符合预想的同步模型的第三方库，这虽然只能覆盖一部分的第三方库，但是通过严苛的源码审查、付出代价高昂的测试成本，也可以勉强用于实际项目开发了；但其他机制不够完善：协程间通讯、协程同步、调试等，因此对开发人员的要求很高，深谙底层机制才能写出没有问题的代码；再加上hook不完善带来的隐患，开发过程可谓是步步惊心、如履薄冰。

更易懂的协程库： https://github.com/yyzybb537/libgo
用法参考其 tutorial 下面的操作，用起来似乎非常简单。

## ORM 数据库工具 Bun
ref: https://github.com/BrainlessLabs/bun
说明： https://www.codeproject.com/Articles/1100449/Cplusplus-Object-Relational-Mapping-ORM-Eating-the


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





