#ifndef COMPONENTMASK_H_
#define COMPONENTMASK_H_

#include "component.h"
#include <stdint.h>

class ComponentMask {
  uint32_t mask = 0;

  template <typename ComponentType> void addComponent() {
    mask |= (1 << GetComponentFamily<ComponentType>());
  }

  template <typename ComponentType> void removeComponent() {
    mask &= ~(1 << GetComponentFamily<ComponentType>());
  }

  bool isNewMatch(ComponentMask oldMask, ComponentMask systemMask);

  bool isNoLongerMatched(ComponentMask oldMask, ComponentMask systemMask);

  bool matches(ComponentMask systemMask);
};

#endif // COMPONENTMASK_H_
