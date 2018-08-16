/* Classe responsável por criar e gerenciar a janela de trabalho,
   utiliza SDL para a janela e GLEW para a likagem dinâmica do OpenGL
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

// Baseado na Bengine

#ifndef CENGINE_WINDOW_H
#define CENGINE_WINDOW_H

#include <string>

#include <SDL2/SDL.h>
#include <GL/glew.h>

namespace cengine::core {

    /**
     * Flags de criação da janela
     */
    enum WindowFlags {
        INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4
    };

    /**
     * Classe responsável por criar e gerenciar a janela de trabalho,
     * utiliza SDL para a janela e GLEW para a likagem dinâmica do OpenGL
     */
    class Window {
    public:
        Window();
        ~Window();

        /**
         * Cria uma janela SDL com contexto OpenGL
         * @param window_name Nome da janela
         * @param screen_width Largura da janela
         * @param screen_height Altura da janela
         * @param vsync Ativar ou não o Vsync da placa
         * @param window_flags Opções de inicialização da janela
         */
        void createWindow(const std::string &window_name, int screen_width, int screen_height, bool vsync,
                          unsigned int window_flags);
        /**
         * Realiza a troca do buffer de renderização no GL
         */
        void swapBuffer();
        /**
         * Fecha a janela, encerrando o contexto GL e o SDL
         */
        void closeWindow();

        int getScreenWidth();
        int getScreenHeight();
        bool isVsync();
        bool isInitialized();
        void destroy();

    private:
        int _screen_width;
        int _screen_height;

        bool _is_initialized = false;
        bool _vsync = false;

        SDL_Window* _sdl_window;
        SDL_GLContext _gl_context;
    };

}

#endif //CENGINE_WINDOW_H