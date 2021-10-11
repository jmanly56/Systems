cmake_minimum_required(VERSION 3.5)

project(Systems LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



IF (WIN32)
add_executable(Systems WIN32 main.cpp)

target_include_directories(Systems PRIVATE "C:/sdl/include")

target_link_directories(Systems PRIVATE "C:/sdl")

target_link_libraries(Systems PRIVATE SDL2 SDL2main)

ELSE()
add_executable(Systems main.cpp)
find_package(SDL2)

ENDIF()
