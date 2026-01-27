#ifndef SCENE_H
#define SCENE_H

#include "components/Components.h"
#include "ecs/EntityManager.h"

#include <cstddef>
#include <unordered_map>

template <class T> using EntityComponentMap = std::unordered_map<std::size_t, T>;

class Scene
{
  private:
    EntityManager m_sceneEntities;
    EntityComponentMap<CRender> m_sceneRenders;
    EntityComponentMap<CTransform> m_sceneTransforms;
    EntityComponentMap<CInput> m_sceneInputs;

  public:
    Scene();
    ~Scene();

    EntityPointer SceneAddEntity(const std::string &tag);
    const EntityVector &SceneEntities();
    const EntityVector &SceneEntities(const std::string &tag);

    CRender *SceneRender(const Entity &e);
    CTransform *SceneTransform(const Entity &e);
    CInput *SceneInput(const Entity &e);

    void SceneAddRender(const CRender &c, const Entity &e);
    void SceneAddTransform(const CTransform &c, const Entity &e);
    void SceneAddInput(const CInput &c, const Entity &e);

    void Update();
};

#endif
