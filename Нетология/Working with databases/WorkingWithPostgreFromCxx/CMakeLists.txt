cmake_minimum_required(VERSION 3.20)
project(libpqxxTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(libpqxx CONFIG REQUIRED)

add_executable(libpqxxTest main.cpp)
target_link_libraries(libpqxxTest PRIVATE libpqxx::pqxx)