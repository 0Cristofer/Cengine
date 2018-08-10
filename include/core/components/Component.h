//
// Created by hugo_ on 06/08/2018.
//

#ifndef CENGINE_COMPONENT_H
#define CENGINE_COMPONENT_H

#include <GL/glew.h>
#include <core/world/Vector3.h>
#include <core/world/Vector2.h>

namespace cengine::core::actors{
    class AActor;
}

namespace cengine::core::components {

    using namespace cengine::core::actors;
    using namespace cengine::core::world;

    class CComponent {

    public:
        const AActor *actor;

        CComponent()    {}
        ~CComponent()   {}

        virtual void Update() {}

    };


    // --------------------------------------------- COMPONENTES PADRÃO ----------------------------------------------//

    class CTransform : public CComponent {
    public:

        Vector3F position = Vector3F(0,0,0);

        CTransform() : CComponent() {}

        void Translate  (const Vector3F &offset) {}
        void Rotate     (const Vector2F &reference, GLfloat angles) {}
        void Scale      (const Vector3F &vet) {}

    };

}

#endif //CENGINE_COMPONENT_H