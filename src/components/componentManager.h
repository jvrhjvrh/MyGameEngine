#ifndef COMPONENTMANAGER_H_
#define COMPONENTMANAGER_H_

#include "../entities/entity.h"
#include "entityMap.h"
#include <array>
#include <map>
#include <memory>

class BaseComponentManager {
public:
  // BaseComponentManager() = default;
  // virtual ~BaseComponentManager() = default;
  // BaseComponentManager(const BaseComponentManager &) = default;
  // BaseComponentManager &operator=(const BaseComponentManager &) = default;
  // BaseComponentManager(BaseComponentManager &&) = default;
  // BaseComponentManager &operator=(BaseComponentManager &&) = default;
};

template <typename ComponentType>
class ComponentManager : public BaseComponentManager {
public:
  void addComponent(Entity entity, ComponentType &&component) {
    entityMap.add(entity, component);
  }

  void destroyComponent(Entity entity) { entityMap.removeEntity(entity); }

  ComponentType *lookup(Entity entity) { return entityMap.getInstance(entity); }

private:
  EntityMap<ComponentType> entityMap;
};

#endif // COMPONENTMANAGER_H_
