add_executable(caller calluservice.cpp)

target_link_libraries(caller common_lib zookeeper_mt ${PROTOBUF_LIBRARIES})

target_include_directories(caller PRIVATE ${PROJECT_SOURCE_DIR}/include)