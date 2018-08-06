/* Funções que representam os possíveis erros na engine
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_ENGINEERRORS_H
#define CENGINE_ENGINEERRORS_H

#include <string>
#include "Window.h"

namespace cengine {

    /**
     * Imprime o erro na tela e finaliza o programa
     * @param error_string Texto do erro a ser impresso
     */
    extern void fatalError(const std::string &error_string);

    /**
     * Imprime o erro na tela
     * @param error_string Texto do erro a ser impresso
     */
    extern void error(const std::string &error_string);
}

#endif //CENGINE_ENGINEERRORS_H