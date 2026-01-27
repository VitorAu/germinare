#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "ecs/Scene.h"

class Systems
{
  public:
    static void SRender(Scene &scene);
    static void STransform(Scene &scene, float dt);
    static void SInput(Scene &scene);
};

#endif
