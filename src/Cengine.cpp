/* Implementação da classe Cengine
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#include <iostream>
#include "Cengine.h"
#include "core/Exceptions.h"
#include "core/Window.h"
#include "core/components/render/Render.h"

namespace cengine {

    void Cengine::init(const std::string &window_name, int screen_width, int screen_heigth){
        _window_name = window_name;
        _screen_width = screen_width;
        _screen_heigth = screen_heigth;
        _is_initialized = true;
    }

    void Cengine::start() {
        if(!_is_initialized) {
            error("Cengine não está inicializada!");
            return;
        }

        window = new Window();
        window->createWindow(_window_name, _screen_width, _screen_heigth, true, 0);
    }

    void Cengine::run() {
        SDL_Event windowEvent;

        if(!_is_initialized) {
            error("Cengine não está inicializada!");
            return;
        }

        runTest();

        while(true){
            if(SDL_PollEvent(&windowEvent)){
                if(windowEvent.type == SDL_QUIT) break;
            }

            window->swapBuffer();
        }
    }

    void Cengine::stop() {
        if(!_is_initialized) {
            error("Cengine não está inicializada!");
            return;
        }

        window->closeWindow();
        free(window);
    }

    void Cengine::runTest() {
        auto &player = *new actors::AActor();
        player.AddComponent<components::CRender>();
        components::CRender *render = player.GetComponent<components::CRender>();
        std::cout << "Name: " << render->name << std::endl;
    }

    Cengine& Cengine::getInstance() {
        static Cengine instance;

        return instance;
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