cmake_minimum_required(VERSION 3.5.1)
project(Planetary_System)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/spaceBody.cpp src/spaceBody.h src/planet.cpp src/planet.h src/satellite.cpp src/satellite.h src/orbit.cpp src/orbit.h src/asteroid.cpp src/asteroid.h src/space.cpp src/space.h)
add_executable(Planetary_System ${SOURCE_FILES})
target_link_libraries(Planetary_System -lsfml-graphics -lsfml-window -lsfml-system -lglut)