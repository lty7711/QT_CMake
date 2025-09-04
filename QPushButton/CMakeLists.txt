cmake_minimum_required(VERSION 3.30)
project(pushButton)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 导入QT的库
find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} "mainwindow.cpp" mainwindow.ui "mainwindow.h" "main.cpp")

# 指定qt依赖的库和头文件
target_link_libraries(${PROJECT_NAME} PRIVATE
Qt6::Widgets
)