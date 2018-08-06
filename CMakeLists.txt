cmake_minimum_required(VERSION 3.10)
project(Cengine)

set(CMAKE_CXX_STANDARD 11)

add_executable(Cengine cengine_test.cpp src/cengine/cengineBase/Window.cpp src/cengine/cengineBase/include/Window.h src/cengine/cengineBase/include/engineErrors.h src/cengine/cengineBase/engineErrors.cpp src/cengine/Cengine.cpp src/cengine/include/Cengine.h src/cengine/cengineBase/Object.cpp src/cengine/cengineBase/include/Object.h src/cengine/cengineBase/Transform.cpp src/cengine/cengineBase/include/Transform.h  src/cengine/components/Component.h src/cengine/components/drawable/Vertex.cpp src/cengine/components/drawable/include/Vertex.h src/cengine/components/drawable/Drawable.cpp src/cengine/components/drawable/include/Drawable.h)

target_link_libraries(Cengine GL SDL2 GLEW)
