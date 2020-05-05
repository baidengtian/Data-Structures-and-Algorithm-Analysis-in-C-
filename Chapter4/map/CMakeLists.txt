cmake_minimum_required(VERSION 3.11)

project(VSCode_Cpp_CMake)
# 代码路径
aux_source_directory(. DIR_TOOT_SRCS)
# debug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
# 生成可执行的文件
add_executable(VSCode_Cpp_CMake ${DIR_TOOT_SRCS})