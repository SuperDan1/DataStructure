include_directories(${CMAKE_SOURCE_DIR}) #方便查找头文件，如果不指定会出现找不到头文件的问题
add_library(graph SHARED ${CMAKE_CURRENT_LIST_DIR}) # 编译动态库，生成liadd.so