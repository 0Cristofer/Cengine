cmake_minimum_required(VERSION 3.10)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
project(CEngine)

set(CMAKE_CXX_STANDARD 11)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(SDL2
        GIT_REPOSITORY https://github.com/spurious/SDL-mirror
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        )

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_executable(CEngine
        cengine_test.cpp

        include/core/world/Vector3.h
        include/core/world/Vector2.h
        include/core/actors/components/Component.h
        include/core/actors/Actor.h
        include/core/Window.h
        include/core/Exceptions.h
        include/core/CEngine.h)

add_dependencies(CEngine SDL2)