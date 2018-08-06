/* Implementação do componente Drawable
   Autor: Cristofer Oswald
   Data: 06/08/2016 */

#include "include/Drawable.h"

namespace cengine{

    Drawable::Drawable(){
        _priority = 1;
    }

    void Drawable::update() {
        if(_has_ended) {
            for (Vertex *vertex : _vertices) {
                vertex->toDeviceUnits();
            }
        }
    }

    void Drawable::addVertex(float x, float y) {
        if (!_has_ended) {
            _vertices.push_back(new Vertex(x, y));
        }
    }

    void Drawable::endPolygon() {
        for(Vertex* vertex : _vertices){
            _raw_vertices.push_back(*vertex);
        }

        glGenBuffers(1, &_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

        //TODO

        _has_ended = true;
    }

    Drawable::~Drawable() = default;
}