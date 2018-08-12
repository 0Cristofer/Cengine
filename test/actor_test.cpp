//
// Created by hugovs on 11/08/18.
//

#include <iostream>

#include <cengine/Cengine.h>
#include <cengine/scene/Scene.h>
#include <cengine/scene/components/Writer.h>

using namespace cengine::scene;

int main() {

    cengine::Cengine engine;

    auto *actor = new AActor();
    actor->AddComponent<CWriter>();

    auto *scene = new Scene();
    scene->AddActor(actor);

    engine.lifeCycle = dynamic_cast<ILifeCycle*>(scene);
    engine.init("Game", 800, 600);
    engine.start();
    engine.run();
    engine.stop();

    return 0;

}

