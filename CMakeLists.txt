cmake_minimum_required(VERSION 3.10)
project(RPC)

# 查找并链接 Protobuf 库
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

# 添加公共库的源文件
file(GLOB COMMON_SRC_FILES "src/*.cpp" "src/*.pb.cc")

# 添加 caller 和 callee 的源文件
file(GLOB CALLER_SRC_FILES "src/caller/*.cpp")
file(GLOB CALLEE_SRC_FILES "src/callee/*.cpp")

# 创建静态库 common_lib
add_library(common_lib STATIC ${COMMON_SRC_FILES} ${CALLER_SRC_FILES} ${CALLEE_SRC_FILES})

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# 包含所有必要的头文件路径
include_directories(include)

# 分别添加 example 下的子目录
add_subdirectory(example/caller)
add_subdirectory(example/callee)