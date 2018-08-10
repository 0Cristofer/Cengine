/* Implementação das funções de erro
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#include <iostream>

#include <SDL2/SDL.h>

#include "core/Exceptions.h"

namespace cengine::core {

    void fatalError(const std::string &error_string){
        std::cout << error_string << std::endl;
        exit(1);
    }

    void error(const std::string &error_string){
        std::cout << error_string << std::endl;
    }
}