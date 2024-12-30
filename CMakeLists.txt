cmake_minimum_required(VERSION 3.10)
project(RPC)

# 查找并链接Protobuf库
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

file(GLOB COMMON_SRC_FILES "src/*.cpp" "src/*.pb.cc")

file(GLOB CALLER_SRC_FILES "src/caller/*.cpp")
file(GLOB CALLEE_SRC_FILES "src/callee/*.cpp")
add_library(common_lib STATIC ${COMMON_SRC_FILES} ${CALLER_SRC_FILES} ${CALLEE_SRC_FILES})

# file(GLOB MUDUO "src/muduo/*.cpp")
# add_library(common_lib STATIC ${COMMON_SRC_FILES} ${CALLER_SRC_FILES} ${CALLEE_SRC_FILES} ${MUDUO})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_definitions(-DTHREADED)

include_directories(include)

add_subdirectory(example/caller)
add_subdirectory(example/callee)