cmake_minimum_required(VERSION 3.27)
# cmake语法关键字--大/小写无关
# cmake的最低版本号，注意VERSION需要大写

#设置工程名
project(icpac_Control)


set (CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory("src" DIR_SRC)
aux_source_directory("include" DIR_LIB)

set(CMAKE_CXX_STANDARD 17)

link_libraries(libeasyx.a)

link_directories(winmm)

# 添加测试目录

add_executable(icpac_Control ${DIR_SRC} ${DIR_LIB}
        src/LoginRegisterModule.cpp
        include/LoginRegisterModule.h
        src/CalculagraphModel.cpp
        include/CalculagraphModel.h
        src/Teacher.cpp
        include/Teacher.h
        lib/lib-easyx/src/EasyButton.cpp
        lib/lib-easyx/include/EasyButton.h
)

add_subdirectory ("tests/AdminViewTest")