cmake_minimum_required(VERSION 3.27)
# cmake语法关键字--大/小写无关
# cmake的最低版本号，注意VERSION需要大写

set(IS_ARCH_DEMO false)
#设置工程名
project(adminviewtest)

set(CMAKE_CXX_STANDARD 17)
# 设置文件名称
set (appName adminview)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

## 包含库目录
include_directories ("src" RED)


link_libraries(libeasyx.a)

link_directories(winmm)

