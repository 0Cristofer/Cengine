//
// Created by hugo_ on 06/08/2018.
//

#ifndef CENGINE_VECTOR2_H
#define CENGINE_VECTOR2_H

#include "Vector3.h"

namespace CEngine::Core {

    template <typename T>
    class Vector2 : private Vector3<T> {
    public:
        T &e1, &e2;

        template <typename T>
        Vector2(T &e1, T &e2) : Vector3<T>(e1, e2, 0) {}

        template <typename T>
        virtual ~Vector2() : ~Vector3() {}

    };

    // Utilidades
    class Vector2I : public Vector2<int> {};
    class Vector2F : public Vector2<float> {};

}

#endif //CENGINE_VECTOR2_H
