/* Implementação da classe Cengine
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#include <iostream>
#include "cengine/Cengine.h"
#include <cengine/core/Window.h>
#include <cengine/core/Debug.h>

#define FRAME_CAP 60

namespace cengine {

    using namespace cengine::core::debug;

    void Cengine::init(const std::string &window_name, int screen_width, int screen_heigth){
        _window_name = window_name;
        _screen_width = screen_width;
        _screen_heigth = screen_heigth;
        _is_initialized = true;
    }

    void Cengine::start() {
        if(!_is_initialized) {
            std::cerr << "Cengine não está inicializada!";
            return;
        }

        window = new Window();
        window->createWindow(_window_name, _screen_width, _screen_heigth, true, 0);

        lifeCycle->Start();

    }

    void Cengine::run() {
        SDL_Event windowEvent;

        if(!_is_initialized) {
            std::cerr << "Cengine não está inicializada!";
            return;
        }

        try {
            while (true) {

                if (SDL_PollEvent(&windowEvent)) {
                    if (windowEvent.type == SDL_QUIT) break;
                }

                window->swapBuffer();
                lifeCycle->Update();

                SDL_Delay(1000 / FRAME_CAP);

            }
        } catch (std::exception &e) {
            Logger::Log(Logger::Type::FATAL, e.what());
        }

    }

    void Cengine::stop() {
        if(!_is_initialized) {
            std::cerr << "Cengine não está inicializada!";
            return;
        }

        window->closeWindow();
        free(window);
        lifeCycle->Destroy();

    }

    int Cengine::getScreenWidth() const {
        return _screen_width;
    }

    int Cengine::getScreenHeight() const {
        return _screen_heigth;
    }

    const std::string &Cengine::getWindowName() const {
        return _window_name;
    }

}