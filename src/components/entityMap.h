#ifndef ENTITYMAP_H_
#define ENTITYMAP_H_

#include "../entities/entity.h"
#include <memory>
#include <unordered_map>
#include <vector>

template <typename ComponentType> class EntityMap {
public:
  ComponentType *getInstance(Entity entity) {
    return &entityToInstance.at(entity);
  }

  void add(Entity entity, ComponentType &instance) {
    auto instanceMap = entityToInstance.find(entity);
    if (instanceMap == entityToInstance.end()) {
      entityToInstance.insert({entity, instance});
    }
  }

  void removeEntity(Entity entity) { entityToInstance.erase(entity); }

private:
  std::unordered_map<Entity, ComponentType> entityToInstance;
};

#endif // ENTITYMAP_H_
