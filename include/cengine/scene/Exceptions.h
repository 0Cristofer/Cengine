//
// Created by hugovs on 11/08/18.
//

#ifndef CENGINE_SCENE_EXCEPTIONS_H
#define CENGINE_SCENE_EXCEPTIONS_H

#include <stdexcept>

namespace cengine::scene::exception {

    class ComponentNotPresentException : public std::runtime_error {
    public:
        ComponentNotPresentException(const std::string &__arg) : runtime_error(__arg) {}
    };

    class DuplicatedComponentException : public std::runtime_error {
    public:
        DuplicatedComponentException(const std::string &__arg) : runtime_error(__arg) {}
    };

    class SceneNotLoadedException : public std::runtime_error {
    public:
        SceneNotLoadedException(const std::string &__arg) : runtime_error(__arg) {}
    };

}

#endif //CENGINE_SCENE_EXCEPTIONS_H
