//
// Created by hugo_ on 06/08/2018.
//

#ifndef CENGINE_COMPONENT_H
#define CENGINE_COMPONENT_H

namespace CEngine::Core::Component {

    class CComponent {};


    // --------------------------------------------- COMPONENTES PADRÃO ----------------------------------------------//

    class CTransform : public CComponent {
    public:
        Vector3F x, y;

        void Translate(Vector3 offset) {}
        void Rotate(Vector2 reference, float32 angles) {}
        void Scale(Vector3 vet) {}
    };

}

#endif //CENGINE_COMPONENT_H
