cmake_minimum_required(VERSION 3.2.3 FATAL_ERROR)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)

include("${CMAKE_CURRENT_SOURCE_DIR}/danssfml/CMakeInclude.txt")

add_executable(joyrider "main.cpp")

target_link_libraries(joyrider
	sfml-system
	sfml-window
	sfml-graphics
)
