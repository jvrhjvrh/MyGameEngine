#ifndef COMPONENTHANDLE_H_
#define COMPONENTHANDLE_H_

#include "../entities/entity.h"
#include "componentManager.h"

template <typename ComponentType> class ComponentHandle {
  Entity owner;
  ComponentManager<ComponentType> *manager;

public:
  // Empty constructor used for World::unpack()
  ComponentHandle(){};
  ComponentHandle(Entity owner, std::weak_ptr<ComponentType> component,
                  ComponentManager<ComponentType> *manager) {
    this->owner = owner;
    this->component = component;
    this->manager = manager;
  }
  std::weak_ptr<ComponentType> component;

  // handle->member is the same as handle.component->member
  // std::shared_ptr<ComponentType> operator->() const { return
  // component.lock(); }

  void destroy() { manager->destroyComponent(owner); }
};

#endif // COMPONENTHANDLE_H_
