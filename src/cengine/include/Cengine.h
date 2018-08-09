/* Classe principal da engine, singleton, responsável por controlar os outros componentes e utiliza-los
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#ifndef CENGINE_CENGINE_H
#define CENGINE_CENGINE_H

#include "../cengineBase/include/Window.h"
#include "../cengineBase/include/Transform.h"
#include "../cengineBase/include/Object.h"

namespace cengine {

    /**
     * Classe principal da engine, responsável por controlar os outros componentes e utiliza-los
     */
    class Cengine {
    public:
        static Cengine& getInstance();

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

        void runTest(); //Temporário, serve para adicionar objetos para testes

        int getScreenWidth() const;

        int getScreenHeight() const;

        const std::string &getWindowName() const;

    private:
        int _screen_width, _screen_heigth;
        bool _is_initialized = false;

        std::string _window_name;
        std::vector<Object*> _objects;
    };
}

#endif //CENGINE_CENGINE_H
