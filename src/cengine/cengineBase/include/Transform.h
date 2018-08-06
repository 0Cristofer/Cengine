/* Representa a posição do objeto no mundo
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_TRANSFORM_H
#define CENGINE_TRANSFORM_H

namespace cengine {

    class Transform {
    public:
        Transform() = default;
        Transform(float x, float y, float z);

        float getX() const;

        float getY() const;

        float getZ() const;

        void setX(float x);

        void setY(float y);

        void setZ(float z);

    private:
        float _x, _y, _z;
    };
}

#endif //CENGINE_TRANSFORM_H
