cmake_minimum_required(VERSION 3.10)

project(Cengine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Cengine

        include/Cengine.h
        include/core/Exceptions.h
        include/core/Window.h
        include/core/components/Component.h
        include/core/components/render/Render.h
        include/core/actors/Actor.h
        include/core/world/Vector3.h
        include/core/world/Vector2.h

        src/Cengine.cpp
        src/core/Exceptions.cpp
        src/core/Window.cpp
        src/core/components/render/Render.cpp

        cengine_test.cpp)

target_link_libraries(Cengine GL SDL2 GLEW)