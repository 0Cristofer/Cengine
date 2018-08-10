/* Implementação da classe Window
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

// Baseado na Bengine

#include "core/Window.h"
#include "core/Exceptions.h"

namespace cengine::core {

    Window::~Window() = default;

    Window::Window() = default;

    void Window::createWindow(const std::string &window_name, int screen_width, int screen_height, bool vsync,
                              unsigned int window_flags){
        Uint32 flags;

        SDL_Init(SDL_INIT_VIDEO);

        _screen_width = screen_width;
        _screen_height = screen_height;

        flags = SDL_WINDOW_OPENGL;

        //Faz a operação binaria para verificar quais flags foram passadas
        if (window_flags & INVISIBLE) {
            flags = flags | SDL_WINDOW_HIDDEN;
        }
        if (window_flags & FULLSCREEN) {
            flags = flags | SDL_WINDOW_FULLSCREEN_DESKTOP;
        }
        if (window_flags & BORDERLESS) {
            flags = flags | SDL_WINDOW_BORDERLESS;
        }

        // Configuração de atributos para forçar compatibilidade
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        // Configurações de desempenho
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

        //Cria a janela principal
        _sdl_window = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width,
                                      screen_height,
                                      flags);

        if (_sdl_window == nullptr) {
            fatalError("Erro ao iniciar janela SDL");
        }

        //Inicializa o openGl
        _gl_context = SDL_GL_CreateContext(_sdl_window);

        if (_gl_context == nullptr) {
            fatalError("Erro ao criar contexto OpenGL");
        }

        //Verifica a verão do opengl
        std::printf("**** OpenGL versão: %s ****\n", glGetString(GL_VERSION));

        //Inicia os sistemas do glew
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            fatalError("Não foi possível inicializar glew");
        }

        /* Não funciona ainda
        //Cor padrão será azul
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        //Ativa o uso do alfa
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        */

        //Configura o vsync
        _vsync = vsync;
        SDL_GL_SetSwapInterval(_vsync);

        _is_initialized = true;
    }

    void Window::swapBuffer(){
        if(!_is_initialized) {
            error("Janela não inicializada");
            return;
        }

        SDL_GL_SwapWindow(_sdl_window);
    }

    void Window::closeWindow() {
        if(!_is_initialized) {
            error("Janela não inicializada");
            return;
        }

        SDL_GL_DeleteContext(_gl_context);
        SDL_Quit();
    }

    int Window::getScreenWidth(){
        return _screen_width;
    }

    int Window::getScreenHeight(){
        return _screen_height;
    }

    bool Window::isVsync(){
        return _vsync;
    }

    bool Window::isInitialized() {
        return _is_initialized;
    }
}