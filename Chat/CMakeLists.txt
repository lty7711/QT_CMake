cmake_minimum_required(VERSION 3.30)
project(Chat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# AutoUic 搜索 ui 文件的目录
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

# 搜索当前目录下的源文件 GLOB_RECURSE 递归搜索选项
file(GLOB SOURCE_FILES *.cpp)

file(GLOB_RECURSE HEADER_FILES *.h)

file(GLOB RESOURCE_FILES *.qrc)

#[[foreach(src ${SOURCE_FILES})
    message(STATUS "Found source: ${src}")
endforeach()]]

#[[foreach(src ${HEADER_FILES})
    message(STATUS "Found head: ${src}")
endforeach()]]

# 创建可执行文件
add_executable(${PROJECT_NAME} 
    ${SOURCE_FILES}
    ${HEADER_FILES}
    ${RESOURCE_FILES}
)

target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES})

target_include_directories(Chat PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}       # 源码根目录
    ${CMAKE_CURRENT_SOURCE_DIR}/include # 你的 include 子目录
    ${CMAKE_CURRENT_BINARY_DIR}       # 构建目录（存放自动生成的 ui_*.h）
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)

# 指定qt依赖的库和头文件
target_link_libraries(${PROJECT_NAME} PRIVATE
Qt6::Widgets
Qt6::Core
Qt6::Gui
Qt6::Network
)