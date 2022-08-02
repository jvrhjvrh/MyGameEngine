#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <type_traits>

class Game;
class Entity;

struct ComponentCounter {
  static int familyCounter;
};

template <typename ComponentType> struct Component {
  static inline int family() {
    static int family = ComponentCounter::familyCounter++;
    return family;
  }
  Game *game;
  Entity *entity;
};

// Util method for getting family given type
template <typename C> static int GetComponentFamily() {
  return Component<typename std::remove_const<C>::type>::family();
}

#endif // COMPONENT_H_
