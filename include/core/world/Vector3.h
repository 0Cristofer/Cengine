//
// Created by hugo_ on 06/08/2018.
//

#ifndef CENGINE_VECTOR3_H
#define CENGINE_VECTOR3_H

#include <GL/glew.h>

namespace cengine::core::world {

    template <typename T>
    class Vector3 {
    public:
        T e1, e2, e3;
        Vector3(T e1, T e2, T e3) : e1(e1), e2(e2), e3(e3) {}
    };

    // Utilidades
    class Vector3I : public Vector3<GLint> {
    public:
        Vector3I(GLint e1, GLint e2, GLint e3) : Vector3(e1, e2, e3) {}
    };

    class Vector3F : public Vector3<GLfloat> {
    public:
        Vector3F(GLfloat e1, GLfloat e2, GLfloat e3) : Vector3(e1, e2, e3) {}
    };

}

#endif //CENGINE_VECTOR3_H
