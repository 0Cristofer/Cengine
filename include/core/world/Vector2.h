//
// Created by hugo_ on 06/08/2018.
//

#ifndef CENGINE_VECTOR2_H
#define CENGINE_VECTOR2_H

#include <GL/glew.h>
#include "Vector3.h"

namespace cengine::core::world {

    template <typename T>
    class Vector2 : public Vector3<T> {
    public:
        Vector2(T e1, T e2) : Vector3<T>(e1, e2, 0) {}
    };

    // Utilidades
    class Vector2I : public Vector2<GLint> {
    public:
        Vector2I(GLint e1, GLint e2) : Vector2(e1, e2) {}
    };

    class Vector2F : public Vector2<GLfloat> {
    public:
        Vector2F(GLfloat e1, GLfloat e2) : Vector2(e1, e2) {}
    };

}

#endif //CENGINE_VECTOR2_H
