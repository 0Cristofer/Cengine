/* Arquivo principal para os testes da engine
   Autor: Cristofer Oswald
   Data: 06/08/2018*/

#include "src/cengine/include/Cengine.h"

int main(){
    auto cengine = cengine::Cengine::getInstance();

    cengine.init("Such Game", 800, 800);
    cengine.start();
    cengine.run();
    cengine.stop();

    return 0;
}