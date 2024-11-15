cmake_minimum_required(VERSION 3.27)
# cmake语法关键字--大/小写无关
# cmake的最低版本号，注意VERSION需要大写

#设置工程名
project(icpac_Control)


#set (CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory("src" DIR_SRC)
aux_source_directory("include" DIR_LIB)
aux_source_directory("resources" DIR_RES)

set(CMAKE_CXX_STANDARD 17)

link_libraries(libeasyx.a)

link_directories(winmm)

# 添加测试目录

add_executable(icpac_Control ${DIR_SRC} ${DIR_LIB}
        src/LoginRegisterModule.cpp
        include/LoginRegisterModule.h
        src/CalculagraphModel.cpp
        include/CalculagraphModel.h
        include/Star.h
        src/UserView.cpp
        include/UserView.h
        ${1_LIB}
)

add_subdirectory ("tests/AdminViewTest")

add_subdirectory ("include/game/2048")