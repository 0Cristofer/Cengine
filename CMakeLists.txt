cmake_minimum_required(VERSION 3.10)

project(Cengine)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Cengine

        include/cengine/Cengine.h
        include/cengine/core/Window.h
        include/cengine/core/LifeCycle.h
        include/cengine/core/data/Vector3.h
        include/cengine/core/data/Vector2.h
        include/cengine/scene/components/Component.h
        include/cengine/scene/components/Transform.h
        include/cengine/scene/components/Render.h
        include/cengine/scene/actors/Actor.h
        include/cengine/scene/Scene.h
        include/cengine/scene/Exceptions.h

        src/Cengine.cpp
        src/core/Window.cpp

        test/actor_test.cpp include/cengine/scene/components/Writer.h include/cengine/core/Debug.h)

target_link_libraries(Cengine GL SDL2 GLEW)