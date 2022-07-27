#ifndef GAME_H_
#define GAME_H_

#include "../components/component.h"
#include "../components/componentHandle.h"
#include "../components/componentManager.h"
#include "../components/componentMask.h"
#include "../entities/entityManager.h"

#include <memory>

class EntityHandle;

class Game {
public:
  explicit Game();

  EntityHandle createEntity();
  // void destroyEntity(Entity entity);

  template <typename ComponentType>
  void addCustomComponentManager(
      std::unique_ptr<ComponentManager<ComponentType>> manager) {
    int family = GetComponentFamily<ComponentType>();
    if (family >= componentManagers.size()) {
      componentManagers.resize(family + 1);
    }
    componentManagers[family] = manager;
  }

  template <typename ComponentType>
  void addComponent(Entity const &entity, ComponentType &&component) {
    ComponentManager<ComponentType> *manager =
        getComponentManager<ComponentType>();
    manager->addComponent(entity, std::forward<ComponentType>(component));
    // ComponentMask oldMask = entityMasks[entity];
    // entityMasks[entity].addComponent<ComponentType>();

    // updateEntityMask(entity, oldMask);
  }

  template <typename ComponentType> void removeComponent(Entity const &entity) {
    ComponentManager<ComponentType> *manager =
        getComponentManager<ComponentType>();
    ComponentHandle<ComponentType> component = manager->lookup(entity);
    component.destroy();

    // ComponentMask oldMask = entityMasks[entity];
    // entityMasks[entity].removeComponent<ComponentType>();

    // updateEntityMask(entity, oldMask);
  }

  template <typename ComponentType, typename... Args>
  void unpack(Entity e, ComponentHandle<ComponentType> &handle,
              ComponentHandle<Args> &...args) {
    auto mgr = getComponentManager<ComponentType>();
    handle = ComponentHandle<ComponentType>(e, mgr->lookup(e), mgr);

    // Recurse
    unpack<Args...>(e, args...);
  }

  // Base case
  template <typename ComponentType>
  void unpack(Entity e, ComponentHandle<ComponentType> &handle) {
    auto mgr = getComponentManager<ComponentType>();
    handle = ComponentHandle<ComponentType>(e, mgr->lookup(e), mgr);
  }

private:
  std::unique_ptr<EntityManager> entityManager;
  std::vector<std::unique_ptr<BaseComponentManager>> componentManagers;
  // std::map<Entity, ComponentMask> entityMasks;

  void updateEntityMask(Entity const &entity, ComponentMask oldMask);

  template <typename ComponentType>
  ComponentManager<ComponentType> *getComponentManager() {
    int family = GetComponentFamily<ComponentType>();

    if (family >= componentManagers.size()) {
      componentManagers.resize(family + 1);
    }

    if (!componentManagers[family]) {
      componentManagers[family] =
          std::make_unique<ComponentManager<ComponentType>>();
    }

    return static_cast<ComponentManager<ComponentType> *>(
        componentManagers[family].get());
  }
};

#endif // GAME_H_
