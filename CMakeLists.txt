cmake_minimum_required(VERSION 3.17)
project(encodingTest)

set(CMAKE_CXX_STANDARD 14)
include_directories(C:\\ws\\lib\\boost_1_71_0)
link_directories(C:\\ws\\lib\\boost_1_71_0\\stage\\lib)

add_executable(encodingTest main.cpp CodeDetect.cpp CodeDetect.h)

target_link_libraries(encodingTest boost_locale-mgw93-mt-d-x64-1_71 iconv)