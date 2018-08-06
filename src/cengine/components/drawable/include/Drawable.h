/* Componente que define objetos que poderão ser desenhados na tela
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_DRAWABLE_H
#define CENGINE_DRAWABLE_H


#include <vector>
#include <GL/glew.h>
#include "Vertex.h"
#include "../../Component.h"

namespace cengine {
    class Drawable : Component {
    public:
        Drawable();

        void update() override;

        void addVertex(float x, float y);

        void endPolygon();

        ~Drawable();

    private:
        bool _has_ended = false;
        GLuint _vbo;

        std::vector<Vertex*> _vertices;
        std::vector<Vertex> _raw_vertices;
    };
}

#endif //CENGINE_DRAWABLE_H
