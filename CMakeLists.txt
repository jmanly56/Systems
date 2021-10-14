cmake_minimum_required(VERSION 3.5)

project(Systems LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



IF (WIN32)
add_executable(Systems WIN32 main.cpp starsystem.h starsystem.cpp star.h star.cpp "idrawable.h" "graphics.h" "graphics.cpp" "engine.h" "engine.cpp" "input.h" "input.cpp" "gameobjects/gameobject.h" "gameobjects/gameobject.cpp" "gameobjects/player.h" "gameobjects/player.cpp")

target_include_directories(Systems PRIVATE "C:/sdl/include")
set_target_properties(Systems PROPERTIES
LINK_FLAGS /SUBSYSTEM:CONSOLE
)
target_link_directories(Systems PRIVATE "C:/sdl")



ELSE()

find_package(SDL2)
add_executable(Systems main.cpp starsystem.h starsystem.cpp star.h star.cpp)

ENDIF()

target_link_libraries(Systems PRIVATE SDL2 SDL2main SDL2_image)
