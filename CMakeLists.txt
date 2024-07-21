cmake_minimum_required(VERSION 3.28)
project(Within_the_Light)

set(CMAKE_CXX_STANDARD 17)

# Replace these paths with the correct paths for your GLFW installation
include_directories(C:/dev/glfw-3.4.bin.WIN64/include)
include_directories(OGL3D/include)
link_directories(C:/dev/glfw-3.4.bin.WIN64/lib-mingw-w64)

add_executable(Within_the_Light Game/main.cpp
        OGL3D/include/OGL3D/Window/Window.h
        OGL3D/source/OGL3D/Window/Window.cpp
        OGL3D/include/OGL3D/Game/Game.h
        OGL3D/source/OGL3D/Game/Game.cpp)
target_link_libraries(Within_the_Light glfw3)