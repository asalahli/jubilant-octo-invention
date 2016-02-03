cmake_minimum_required (VERSION 3.4)

project (Game)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++0x)
set(PROJECT_LINK_LIBS libsfml-window.so libsfml-graphics.so libsfml-system.so libBox2D.so)

#set(SOURCES src/main.cpp)
file(GLOB SOURCES "src/*.cpp")
 
add_executable(Game ${SOURCES})
target_link_libraries(Game ${PROJECT_LINK_LIBS})