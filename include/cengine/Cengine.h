/* Classe principal da engine, singleton, responsável por controlar os outros componentes e utiliza-los
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_CENGINE_H
#define CENGINE_CENGINE_H

#include <string>
#include <vector>

#include <cengine/core/Window.h>
#include <cengine/core/LifeCycle.h>
#include <cengine/core/data/Vector3.h>
#include <cengine/core/data/Vector2.h>

namespace cengine {

    using namespace cengine::core;
    /**
     * Classe principal da engine, responsável por controlar os outros componentes e utiliza-los
     */
    class Cengine {
    public:

        /**
         * Inicializa a instância da engine com o seu nome e tamanho de janela
         * @param window_name Nome da janela
         * @param screen_width Largura
         * @param screen_heigth Altura
         */
        void init(const std::string &window_name, int screen_width, int screen_heigth);

        /**
         * Inicia os sistemas necessários para a engine. Abre a janela inicial
         */
        void start();

        /**
         * Executa o loop principal de execução
         */
        void run();

        /**
         * Termina a execução, finalizando os componentes da engine
         */
        void stop();

        int getScreenWidth() const;

        int getScreenHeight() const;

        const std::string &getWindowName() const;

        ILifeCycle *lifeCycle = nullptr;

    private:
        int _screen_width, _screen_heigth;
        bool _is_initialized = false;

        std::string _window_name;
        Window *window;

    };

}

#endif //CENGINE_CENGINE_H
