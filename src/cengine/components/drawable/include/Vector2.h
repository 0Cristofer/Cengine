/* Representa um vértice de um objeto que pode ser desenhado na tela
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_VERTEX_H
#define CENGINE_VERTEX_H

namespace cengine {
    struct Position{
    public:
        float x, y;
    };

    class Vertex {
    public:
        Position position;

        Vertex(float x, float y);

        /**
         * A partir de coordenadas do mundo, as transforma em coordenadas normalizadas
         */
        void toDeviceUnits();

        /**
         * A partir de coordenadas do dispositivo, as transforma em coordenadas do mundo
         */
        void toWorldUnits();

    };
}

#endif //CENGINE_VERTEX_H
