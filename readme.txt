cmake教程：
    https://subingwen.cn/


cmake .
cmake -G"MinGW Makefiles" .

make 调用了mingw/bin 中的make.exe, 可能是mingw32-make.exe

set用法：
1、设定变量
    set(VAR sub.cpp add.cpp)
    add_executable(app ${VAR})
2、指定C++标准
3、指定可执行程序输出路径
    set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

指定C++标准：
1、CMakeLists.txt文件中加入 set(CMAKE_CXX_STANDARD 17)
2、执行cmake时添加参数，如
    cmake . -DCMAKE_CXX_STANDARD=17

搜索文件：
1、
    aux_source_directory(<dir> <variable>)
2、
    file(GLOB/GLOB_RECURSE 变量名 要搜索的文件路径和文件类型)
    GLOB:当前目录
    GLOB_RECURSE:当前目录以及子目录

PROJECT_SOURCE_DIR 
PROJECT_CURRENT_SOURCE_DIR 当前cmakelist.txt所在目录
cmake .. # ..所在的目录就是PROJECT_SOURCE_DIR

包含头文件：
    include_directories(<头文件路径>)

制作库
    add_library(库名称 STATIC/SHARED 源文件)

指定库文件生成的路径
    set(LIBRARY_OUTPUT_PATH <目录>) # 动态库、静态库均可
    set(EXECUTABLE_OUTPUT_PATH <目录>) # 仅动态库

链接库文件命令：
    link_libraries(<static lib> [<static lib>...])
    link_directories(<path> )