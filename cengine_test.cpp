/* Arquivo principal para os testes da engine
   Autor: Cristofer Oswald
   Data: 06/08/2018*/

#include <iostream>
#include <core/components/render/Render.h>
#include "Cengine.h"

using namespace cengine;

int main() {

    Cengine engine;
    engine.init("Unit Test", 800, 600);
    engine.start();
    engine.run();
    engine.stop();

    return 0;
}