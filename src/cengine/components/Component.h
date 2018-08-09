//
// Created by cristofer on 06/08/18.
//

#ifndef CENGINE_COMPONENT_H
#define CENGINE_COMPONENT_H


namespace cengine {

    class Component {
    public:

        Component() = default;
        virtual ~Component() = default;

        virtual void update() = 0;

        static bool comp(const cengine::Component* c1, const cengine::Component* c2){
            return c1->_priority < c2->_priority;
        }

    protected:
        int _priority;
    }
    ;
}

#endif //CENGINE_COMPONENT_H
