cmake_minimum_required(VERSION 3.23)
project(HrmlParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(HrmlParser main.cpp Utils/Utils.cpp Utils/Utils.hpp Utils/Utils.tpp Hrml/Parser.cpp Hrml/Parser.hpp Hrml/Types.hpp Hrml/Types.cpp)
