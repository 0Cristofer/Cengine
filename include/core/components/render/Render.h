//
// Created by hugovs on 09/08/18.
//

#ifndef CENGINE_RENDER_H
#define CENGINE_RENDER_H

#include <string>
#include "core/components/Component.h"

namespace cengine::core::components {

    class CRender : public CComponent {
    public:
        std::string name = "Render";
        CRender() : CComponent() {}

        void Update() override;


    private:
        CTransform _transform;

    };

}

#endif //CENGINE_RENDER_H
