# example/callee/CMakeLists.txt
add_executable(callee userservice.cpp)

# 链接 common_lib 和 WebServer 库
target_link_libraries(callee common_lib WebServer ${PROTOBUF_LIBRARIES})

# 添加 include 路径
target_include_directories(callee PRIVATE ${PROJECT_SOURCE_DIR}/include)