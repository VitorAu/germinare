#include "ecs/Scene.h"

#include "systems/InputSystem.h"

Scene::Scene() = default;

Scene::~Scene() = default;

EntityPointer Scene::SceneAddEntity(const std::string &tag)
{
    auto e = m_sceneEntities.CreateEntity(tag);
    return e;
}

const EntityVector &Scene::SceneEntities()
{
    return m_sceneEntities.Entities();
}

const EntityVector &Scene::SceneEntities(const std::string &tag)
{
    return m_sceneEntities.Entities(tag);
}

CInput *Scene::SceneInput(const Entity &e)
{
    std::size_t eId = e.Id();
    auto it = m_sceneInputs.find(eId);
    return &it->second;
}

void Scene::SceneAddInput(const CInput &c, const Entity &e)
{
    std::size_t eId = e.Id();
    m_sceneInputs[eId] = c;
}

void Scene::Update()
{
    m_sceneEntities.Update();

    InputSystem::Update(*this);
}
