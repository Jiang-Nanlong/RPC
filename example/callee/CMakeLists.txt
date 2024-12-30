add_executable(callee userservice.cpp)

target_link_libraries(callee common_lib WebServer zookeeper_mt ${PROTOBUF_LIBRARIES})
# target_link_libraries(callee common_lib ${PROTOBUF_LIBRARIES})

target_include_directories(callee PRIVATE ${PROJECT_SOURCE_DIR}/include)