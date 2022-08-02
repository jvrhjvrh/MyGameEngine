#ifndef EVENT_H_
#define EVENT_H_

#include "../entities/entity.h"
#include <type_traits>

struct eventCounter {
  static int familyCounter;
};

template <typename EventType> struct Event {
  static inline int family() {
    static int family = eventCounter::familyCounter++;
    return family;
  }
  EventType event;
};

template <typename C> static int GetEventFamily() {
  return Event<typename std::remove_const<C>::type>::family();
}

int eventCounter::familyCounter = 0;

#endif // EVENT_H_
