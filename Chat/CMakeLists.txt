cmake_minimum_required(VERSION 3.30)
project(Chat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 搜索当前目录下的源文件 GLOB_RECURSE 递归搜索选项
file(GLOB SOURCE_FILES *.cpp)

file(GLOB HEADER_FILES *.h)

file(GLOB UI_FILES *.ui)

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
    ${UI_FILES}
    ${RESOURCE_FILES}
)

target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "D:/Code/QT_Cmake/build/Chat/Chat_autogen/include_Release")

# 指定qt依赖的库和头文件
target_link_libraries(${PROJECT_NAME} PRIVATE
Qt6::Widgets
Qt6::Core
Qt6::Gui
)