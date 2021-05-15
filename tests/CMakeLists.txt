add_executable(${PROJECT_NAME} unittest.cc SeqListTest.cc)
include_directories(../List)
target_link_libraries(${PROJECT_NAME}
    gtest
    gmock
    pthread
)