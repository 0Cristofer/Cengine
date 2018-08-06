/* Implementação da classe Object
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#include <algorithm>
#include "include/Object.h"

namespace cengine{

    Object::Object(Transform* transform) : _transform(transform) {}

    void Object::update() {
        for(Component* c : _components){
            c->update();
        }
    }

    void Object::addComponent(Component* component) {
        _components.push_back(component);
        std::sort(_components.begin(), _components.end(), Component::comp);
    }

    Object::~Object() {

    }
}