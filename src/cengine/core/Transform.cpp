/* Implementação da classe Transform
   Autor: Cristofer Oswald
   Data: 06/07/2018 */

#include "../../../include/core/components/Transform.h"

namespace cengine {

    Transform::Transform(float x, float y, float z) : _x(x), _y(y), _z(z) {}

    float Transform::getX() const {
        return _x;
    }

    float Transform::getY() const {
        return _y;
    }

    float Transform::getZ() const {
        return _z;
    }

    void Transform::setX(float x) {
        _x = x;
    }

    void Transform::setY(float y) {
        _y = y;
    }

    void Transform::setZ(float z) {
        _z = z;
    }

}