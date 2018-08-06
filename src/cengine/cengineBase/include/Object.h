/* Objeto mais simples da engine, utilizado para hospedar componentes. Tem apenas uma posição simples no mundo
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_OBJECT_H
#define CENGINE_OBJECT_H

#include <vector>

#include "Transform.h"
#include "../../components/Component.h"

namespace cengine {
    class Object {
    public:
        explicit Object(Transform* transform);

        /**
         * Atualiza os componentes no mundo
         */
        void update();

        void addComponent(Component* component);

        ~Object();

    private:
        Transform* _transform;

        std::vector<Component*> _components;
    };
}

#endif //CENGINE_OBJECT_H
