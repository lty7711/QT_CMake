cmake_minimum_required(VERSION 3.30)
project(Chat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 定义源文件
set(SOURCE_FILES
    main.cpp
    mainwindow.cpp
)

# 定义头文件
set(HEADER_FILES
    mainwindow.h
)

# 定义UI文件
set(UI_FILES
    mainwindow.ui
)

# 创建可执行文件
add_executable(${PROJECT_NAME} 
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${UI_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE "D:/Code/QT_Cmake/build/Chat/Chat_autogen/include_Release")

# 指定qt依赖的库和头文件
target_link_libraries(${PROJECT_NAME} PRIVATE
Qt6::Widgets
Qt6::Core
Qt6::Gui
)