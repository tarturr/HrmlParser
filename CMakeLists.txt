cmake_minimum_required(VERSION 3.23)
project(HrmlParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(HrmlParser main.cpp Utils/Utils.cpp Utils/Utils.hpp Parsing/HrmlParser.cpp Parsing/HrmlParser.hpp Utils/Utils.tpp Parsing/TagAttributes.cpp Parsing/TagAttributes.hpp)
