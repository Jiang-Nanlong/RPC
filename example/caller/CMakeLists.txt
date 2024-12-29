# example/caller/CMakeLists.txt
add_executable(caller calluservice.cpp)

# 只链接 common_lib 和 Protobuf 库
target_link_libraries(caller common_lib ${PROTOBUF_LIBRARIES})

# 添加 include 路径
target_include_directories(caller PRIVATE ${PROJECT_SOURCE_DIR}/include)