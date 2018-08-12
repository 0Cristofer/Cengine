//
// Created by hugovs on 09/08/18.
//

#ifndef CENGINE_RENDER_H
#define CENGINE_RENDER_H

#include <string>
#include <cengine/scene/components/Component.h>
#include "Transform.h"

namespace cengine::scene::actor {
    class AActor;
}

namespace cengine::scene::component {

    class CRender : public CComponent {
    public:

        void Start() override {
            _transform = actor->GetComponent<CTransform>();
        }

        void Update() override {}


    private:
        CTransform *_transform;

    };

}

#endif //CENGINE_RENDER_H
