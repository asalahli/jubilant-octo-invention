cmake_minimum_required (VERSION 3.4)

project (Game)

if (UNIX)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++0x -g")
    set(PROJECT_LINK_LIBS sfml-window sfml-graphics sfml-system Box2D)
endif (UNIX)

if (MSVC)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " /Zi ")
    set(PROJECT_LINK_LIBS sfml-window.lib sfml-graphics.lib sfml-system.lib Box2D.lib)
    include_directories("lib/SFML-2.3.2/include" "lib/Box2D-2.3.1/include")
    link_directories("lib/SFML-2.3.2/lib" "lib/Box2D-2.3.1/lib")
endif (MSVC)

file(GLOB SOURCES "src/*.cpp")
 
add_executable(Game ${SOURCES})
target_link_libraries(Game ${PROJECT_LINK_LIBS})