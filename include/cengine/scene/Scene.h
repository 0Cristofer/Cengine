//
// Created by hugovs on 11/08/18.
//

#ifndef CENGINE_SCENE_H
#define CENGINE_SCENE_H

#include <map>
#include <vector>
#include <cengine/scene/actors/Actor.h>
#include <cengine/scene/Exceptions.h>

namespace cengine::scene {

    using namespace cengine::scene::actor;
    using namespace cengine::scene::exception;

    class Scene : public ILifeCycle {
    private:
        std::vector<AActor*> _actors;

    public:
        void AddActor(AActor *actor) {
            this->_actors.emplace_back(actor);
        }

        virtual void Start() {
            for (auto &a : _actors)
                a->Start();
        }

        virtual void Update() {
            for (auto &a : _actors)
                a->Update();
        }

        virtual void Destroy() {
            for (auto &a : _actors)
                a->Destroy();
        }

    };

    class SceneManager {

    private:
        std::map<std::string, Scene*> _scenes;
        Scene *_currentScene = nullptr;

    public:
        template<typename T, typename std::enable_if<std::is_base_of<Scene, T>::value>::type * = nullptr>
        void LoadScene() {
            _scenes[typeid(T).name()] = new T();
        }

        template<typename T, typename std::enable_if<std::is_base_of<Scene, T>::value>::type * = nullptr>
        void StartScene() {
            Scene *scene = _scenes[typeid(T).name()];
            if (scene == nullptr)
                throw new cengine::scene::exception::SceneNotLoadedException("Attempt to start unloaded scene.");
            scene->Start();
            _currentScene = scene;
        }

        template<typename T, typename std::enable_if<std::is_base_of<Scene, T>::value>::type * = nullptr>
        void DestroyScene() {
            Scene *scene = _scenes[typeid(T).name()];
            if (scene == nullptr)
                throw cengine::scene::exception::SceneNotLoadedException("Attempt to destroy unloaded scene.");
            scene->Destroy();
        }

        Scene *GetCurrentScene() {
            return _currentScene;
        }

    };

}

#endif //CENGINE_SCENE_H
