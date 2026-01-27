#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "ecs/Entity.h"

#include <memory>
#include <unordered_map>
#include <vector>

class Scene;

using EntityPointer = std::shared_ptr<Entity>;
using EntityVector = std::vector<EntityPointer>;
using EntityMap = std::unordered_map<std::string, EntityVector>;

class EntityManager
{
    friend class Scene;

  private:
    EntityVector m_entitiesToAdd;
    EntityVector m_entitiesVec;
    EntityMap m_entitiesMap;
    std::size_t m_entitiesTotal = 0;

    EntityPointer CreateEntity(const std::string &entityTag);
    const EntityVector &Entities();
    const EntityVector &Entities(const std::string &entityTag);

    void Update();
    void Delete();

  public:
    EntityManager();
    ~EntityManager();
};

#endif
