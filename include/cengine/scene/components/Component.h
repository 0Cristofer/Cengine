//
// Created by hugo_ on 06/08/2018.
//

#ifndef CENGINE_COMPONENT_H
#define CENGINE_COMPONENT_H

#include <GL/glew.h>
#include <cengine/core/data/Vector2.h>
#include <cengine/core/LifeCycle.h>

namespace cengine::scene::actor {
    class AActor;
}

namespace cengine::scene::component {

    using namespace cengine::scene::actor;
    using namespace cengine::core::data;
    using namespace cengine::core;

    class CComponent : public ILifeCycle {
    public:

        bool enabled = true;
        AActor *actor;

        CComponent()    {}
        ~CComponent()   {}

        virtual void Start() {}
        virtual void Update() {}
        virtual void Destroy() { delete this; }

    };


}

#endif //CENGINE_COMPONENT_H