/* Implementação da classe Vertex
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#include "include/Vector2.h"
#include "../../include/Cengine.h"

namespace cengine{

    Vertex::Vertex(float x, float y){
        position.x = x;
        position.y = y;
    }

    void Vertex::toDeviceUnits() {
        position.x = position.x/window->getScreenWidth();
        position.y = position.y/window->getScreenheigth();
    }

    void Vertex::toWorldUnits() {
        position.x = position.x*window->getScreenWidth();
        position.y = position.y*window->getScreenheigth();

    }
}