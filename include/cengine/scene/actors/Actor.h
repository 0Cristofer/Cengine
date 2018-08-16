/* Objeto mais simples da engine, utilizado para hospedar componentes. Tem apenas uma posição simples no mundo
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_ACTOR_H
#define CENGINE_ACTOR_H

#include <string>
#include <map>
#include <cengine/scene/components/Component.h>
#include <cengine/scene/components/Transform.h>
#include <cengine/scene/Exceptions.h>

namespace cengine::scene::actor {

    using namespace cengine::scene::component;
    using namespace cengine::scene::exception;

    class AActor : public ILifeCycle {
    public:

        std::string tag = "actor";

        // Construtore e destrutores
        AActor() { AddComponent<CTransform>(); };

        ~AActor() { };

        virtual void Start()    { for (auto &i : _components) i.second->Start(); }
        virtual void Update()   { for (auto &i : _components) if (i.second->enabled) i.second->Update(); }
        virtual void Destroy()  { for (auto &i : _components) i.second->Destroy(); delete this; }

        template<typename T, typename std::enable_if<std::is_base_of<CComponent, T>::value>::type * = nullptr>
        void AddComponent() {

            if (HasComponent<T>())
                throw DuplicatedComponentException("Component " + std::string(typeid(T).name()) + " already exists in actor.");

            CComponent *c = new T();
            c->actor = this;
            _components[typeid(T).name()] = c;

        }

        template<typename T, typename std::enable_if<std::is_base_of<CComponent, T>::value>::type * = nullptr>
        T *GetComponent() {

            T *c = dynamic_cast<T *>(_components[typeid(T).name()]);
            if (c == nullptr)
                throw ComponentNotPresentException(
                        "Actor has no component of type " + std::string(typeid(T).name()));
            return c;
        }

        template<typename T, typename std::enable_if<std::is_base_of<CComponent, T>::value>::type * = nullptr>
        bool HasComponent() {
            T *c = dynamic_cast<T *>(_components[typeid(T).name()]);
            return c != nullptr;
        }


    private:
        std::map<std::string, CComponent *> _components;


    };


}

#endif //CENGINE_ACTOR_H
