/* Objeto mais simples da engine, utilizado para hospedar componentes. Tem apenas uma posição simples no mundo
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_ACTOR_H
#define CENGINE_ACTOR_H

#include <map>
#include <core/components/Component.h>

namespace cengine::core::actors {

    using namespace cengine::core::components;

    class AActor {
    public:

        // Construtore e destrutores
        AActor()    { AddComponent<CTransform>(); };
        ~AActor()   { for (auto &i : _components) delete i.second; };

        /**
         * Atualiza os componentes no mundo
         */
        virtual void Update() { for (auto &i : _components) i.second->Update(); }

        template<typename T, typename std::enable_if<std::is_base_of<CComponent, T>::value>::type* = nullptr>
        void AddComponent() {
            CComponent *c =  new T();
            c->actor = this;
            _components[typeid(T).name()] = c;
        }

        template<typename T, typename std::enable_if<std::is_base_of<CComponent, T>::value>::type* = nullptr>
        T *GetComponent() { return dynamic_cast<T*>(_components[typeid(T).name()]); }

    private:
        std::map<std::string, CComponent*> _components;


    };

}

#endif //CENGINE_ACTOR_H
