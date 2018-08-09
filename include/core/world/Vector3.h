//
// Created by hugo_ on 06/08/2018.
//

#ifndef CENGINE_VECTOR3_H
#define CENGINE_VECTOR3_H

namespace CEngine::Core {

    template <typename T>
    class Vector3 {
    public:
        T &e1, &e2, &e3;

        template <typename T>
        Vector3(T &e1, T &e2, T &e3) : e1(e1), e2(e2), e3(e3) {}
        virtual ~Vector3() {}

    };

    // Utilidades
    class Vector3I : public Vector3<int32> {};
    class Vector3F : public Vector3<float32> {};

}

#endif //CENGINE_VECTOR3_H
