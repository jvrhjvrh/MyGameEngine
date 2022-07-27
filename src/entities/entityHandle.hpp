#ifndef ENTITYHANDLE_H_
#define ENTITYHANDLE_H_

#include "../components/componentHandle.h"
#include "../game/game.h"
#include "entity.h"

class EntityHandle {
  Entity entity;
  Game *game;

public:
  EntityHandle(Entity entity, Game *game) : entity(entity), game(game) {}
  void destroy() {}

  template <typename ComponentType>
  void addComponent(ComponentType &&component) {
    game->addComponent<ComponentType>(entity,
                                      std::forward<ComponentType>(component));
  }

  template <typename ComponentType> void removeComponent() {
    game->removeComponent<ComponentType>(entity);
  }

  template <typename ComponentType>
  ComponentHandle<ComponentType> getComponent() {
    ComponentHandle<ComponentType> handle;
    game->unpack(entity, handle);
    return handle;
  }
};

#endif // ENTITYHANDLE_H_
