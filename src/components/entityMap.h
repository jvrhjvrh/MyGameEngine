#ifndef ENTITYMAP_H_
#define ENTITYMAP_H_

#include "../entities/entity.h"
#include <memory>
#include <unordered_map>
#include <vector>

template <typename ComponentType> class EntityMap {
public:
  ComponentType *getInstance(Entity entity) {
    return &entityToInstance.at(entity.id);
  }

  void add(Entity entity, ComponentType &instance) {
    auto instanceMap = entityToInstance.find(entity.id);
    if (instanceMap == entityToInstance.end()) {
      entityToInstance.insert({entity.id, instance});
    }
  }

  void removeEntity(Entity entity) { entityToInstance.erase(entity.id); }

private:
  std::unordered_map<uint32_t, ComponentType> entityToInstance;
};

#endif // ENTITYMAP_H_
