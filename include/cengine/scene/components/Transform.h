//
// Created by hugovs on 11/08/18.
//

#ifndef CENGINE_TRANSFORM_H
#define CENGINE_TRANSFORM_H

#include <cengine/scene/components/Component.h>

namespace cengine::scene::component {

    class CTransform : public CComponent {
    public:

        Vector3F position = Vector3F(0, 0, 0);

        void Translate(const Vector3F &offset) {}

        void Rotate(const Vector2F &reference, GLfloat angles) {}

        void Scale(const Vector3F &vet) {}

    };

}
#endif //CENGINE_TRANSFORM_H
