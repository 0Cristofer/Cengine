/* Objeto mais simples da engine, utilizado para hospedar componentes. Tem apenas uma posição simples no mundo
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_OBJECT_H
#define CENGINE_OBJECT_H

#include <map>

#include "components/CTransform.h"
#include "../../../src/cengine/components/Component.h"

namespace CEngine::Core::Actor {

    class AActor {
    public:

        Actor();
        ~Actor();

        /**
         * Atualiza os componentes no mundo
         */
        void Update() {}

        template<class Component T>
        void AddComponent() {
            _components[T] = new T();
        }

        template<class Component T>
        Component &GetComponent() {
            return _components[T];
        }

    private:
        template <class T>
        std::map<T, Component&> _components;

    };

}

#endif //CENGINE_OBJECT_H
