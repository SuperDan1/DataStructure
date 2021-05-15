add_executable(${PROJECT_NAME} unittest.cc)
target_link_libraries(${PROJECT_NAME}
    gtest
    gmock
    pthread
)