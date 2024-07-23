cmake_minimum_required(VERSION 3.28)
project(Within_the_Light)

set(CMAKE_CXX_STANDARD 17)

include_directories(OGL3D/vendor/glad/include)
include_directories(OGL3D/include)

add_executable(Within_the_Light Game/main.cpp
        OGL3D/include/OGL3D/Window/Window.h
        OGL3D/include/OGL3D/Game/Game.h
        OGL3D/source/OGL3D/Game/Game.cpp
        OGL3D/include/OGL3D/Graphics/GraphicsEngine.h
        OGL3D/source/OGL3D/Graphics/GraphicsEngine.cpp
        OGL3D/vendor/glad/src/glad_wgl.c
        OGL3D/vendor/glad/src/glad.c
        OGL3D/include/OGL3D/Math/Vect4.h
        OGL3D/source/OGL3D/Math/Vect4.cpp
        OGL3D/include/OGL3D/Prerequisites.h
        OGL3D/source/OGL3D/Game/Win32/Win32Game.cpp
        OGL3D/source/OGL3D/Graphics/Win32/Win32GraphicsEngine.cpp
        OGL3D/source/OGL3D/Window/Win32/Win32Window.cpp
        OGL3D/source/OGL3D/Window/Win32/Win32Window.cpp
        OGL3D/include/OGL3D/Math/Rect.h
)

target_link_libraries(Within_the_Light opengl32)

