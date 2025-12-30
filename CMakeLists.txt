cmake_minimum_required(VERSION 3.30)
project(Qt_CMake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#[[
	moc = Meta Object Compiler（元对象编译器）
	在 Qt 里，凡是用到 信号/槽机制 或 Q_OBJECT 宏的类，都需要先经过 moc 处理，生成额外的 C++ 源文件。
	打开 CMAKE_AUTOMOC 后，CMake 会自动检测哪些文件包含 Q_OBJECT 宏，然后帮你调用 moc 生成对应的 .cpp 
	文件并加入编译，不需要自己写规则。

	rcc = Resource Compiler（资源编译器）
	Qt 的 .qrc 文件里可以打包图片、图标、QSS 样式表等资源，使用时路径写成 :/images/icon.png 这种。
	打开 CMAKE_AUTORCC 后，CMake 会自动检测项目中的 .qrc 文件，调用 rcc 编译成 C++ 代码加入工程。

	uic = User Interface Compiler（界面编译器）。
	Qt Designer 生成的 .ui 文件其实是 XML 格式的，需要通过 uic 转换成 C++ 头文件（通常是 ui_xxx.h）。
	打开 CMAKE_AUTOUIC 后，CMake 会自动处理 .ui 文件，不需要你手动写 uic 的命令。
]]
set(CMAKE_AUTOMOC ON)   # 自动执行 moc
set(CMAKE_AUTORCC ON)   # 自动执行 rcc (qrc 资源文件)
set(CMAKE_AUTOUIC ON)   # 自动执行 uic (ui 界面文件)

set(Qt6_DIR "D:/Qt/6.9.0/msvc2022_64/lib/cmake/Qt6")
# 设置可执行文件(.exe)和动态库(.dll)输出路径 (Windows上DLL属于RUNTIME)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# 设置共享库输出路径 (Linux上的.so文件)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# 设置静态库(.lib/.a)和导入库输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# 可以用但不推荐：全局包含目录
include_directories(
    "D:/Qt/6.9.0/msvc2022_64/include"
    "D:/Qt/6.9.0/msvc2022_64/include/QtCore"
    "D:/Qt/6.9.0/msvc2022_64/include/QtWidgets"
    "D:/Qt/6.9.0/msvc2022_64/include/QtGui"
)

# 导入QT的库
find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED Network)
# 显式设置包含目录
#add_subdirectory(qPushButton)
add_subdirectory(Chat)