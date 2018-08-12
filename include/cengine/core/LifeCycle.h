//
// Created by hugovs on 11/08/18.
//

#ifndef CENGINE_LIFECYCLE_H
#define CENGINE_LIFECYCLE_H

namespace cengine::core {

    class ILifeCycle {
    public:
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Destroy() = 0;

    };

}

#endif //CENGINE_LIFECYCLE_H
