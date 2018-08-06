/* Implementação da classe Cengine
   Autor: Cristofer Oswald
   Data: 06/08/2018 */

#include "include/Cengine.h"
#include "cengineBase/include/engineErrors.h"
#include "components/drawable/include/Drawable.h"

namespace cengine{

    Window* window;

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

            for(Object* o: _objects){
                o->update();
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
        Object* object = new Object(new Transform(400, 400, 400));
        auto * drawable = new Drawable();

        drawable->addVertex(0, 200);
        drawable->addVertex(200, -200);
        drawable->addVertex(-200, -200);
        drawable->endPolygon();

        object->addComponent((Component*) drawable);

        _objects.push_back(object);
    }

    Cengine& Cengine::getInstance() {
        static Cengine instance;

        return instance;
    }

    int Cengine::getScreenWidth() const {
        return _screen_width;
    }

    int Cengine::getScreenHeigth() const {
        return _screen_heigth;
    }

    const std::string &Cengine::getWindowName() const {
        return _window_name;
    }
}