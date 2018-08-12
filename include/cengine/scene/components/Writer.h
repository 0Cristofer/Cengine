//
// Created by hugovs on 11/08/18.
//

#ifndef CENGINE_WRITER_H
#define CENGINE_WRITER_H

#include <iostream>
#include <cengine/core/Debug.h>
#include "Component.h"
#include <cengine/scene/components/Render.h>

namespace cengine::scene::component {

    using namespace cengine::core::debug;

    class CWriter : public CComponent {

        void Update() override {
            Logger::Log(Logger::NORMAL, "Writing...");
        }

    };

}

#endif //CENGINE_WRITER_H
