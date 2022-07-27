#ifndef COMPONENTHANDLE_H_
#define COMPONENTHANDLE_H_

#include "../entities/entity.h"
#include "componentManager.h"

template <typename ComponentType> class ComponentHandle {
  Entity owner;
  ComponentType *component;
  ComponentManager<ComponentType> *manager;

public:
  // Empty constructor used for World::unpack()
  ComponentHandle(){};
  ComponentHandle(Entity owner, ComponentType *component,
                  ComponentManager<ComponentType> *manager) {
    this->owner = owner;
    this->component = component;
    this->manager = manager;
  }

  // handle->member is the same as handle.component->member
  ComponentType *operator->() const { return component; }

  void destroy() { manager->destroyComponent(owner); }
};

#endif // COMPONENTHANDLE_H_
