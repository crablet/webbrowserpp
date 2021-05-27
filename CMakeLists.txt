cmake_minimum_required(VERSION 2.8)

project(WebBrowser++)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

aux_source_directory(./Include/Browsers/MacOS SRC_LIST)

add_executable(WebBrowserPP main.cpp ${SRC_LIST})

