include_directories(${CMAKE_SOURCE_DIR}) #方便查找头文件，如果不指定会出现找不到头文件的问题
#add_library(list SHARED SeqList.cpp) # 编译动态库，生成liadd.so
#SET_TARGET_PROPERTIES(list PROPERTIES LINKER_LANGUAGE Cxx)

# add_library(liblist SHARED "")

# target_sources(
#     liblist
#     PRIVATE
#         SeqList.cpp
#     )

# target_include_directories(
#     liblist
#     PUBLIC
#         ${CMAKE_CURRENT_LIST_DIR}
#     )