#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include "event.h"
#include <functional>
#include <stdint.h>
#include <unordered_map>
#include <vector>

class BaseEventManager {
public:
  BaseEventManager() = default;
  virtual ~BaseEventManager() = default;
  BaseEventManager(const BaseEventManager &) = default;
  BaseEventManager &operator=(const BaseEventManager &) = default;
  BaseEventManager(BaseEventManager &&) = default;
  BaseEventManager &operator=(BaseEventManager &&) = default;
};

template <typename EventType> class EventManager : public BaseEventManager {
public:
  uint32_t subscribe(std::function<Event<EventType>> func) {
    eventHandlers.push_back(func);
    return eventHandlers.size() - 1;
  };

  void unsubscribe(uint32_t index) {
    eventHandlers.erase(eventHandlers.begin() + index);
  }

  void run(Event<EventType> event) {
    for (auto func : eventHandlers) {
      func(event);
    }
  }

private:
  std::vector<std::function<Event<EventType>>> eventHandlers;
};

#endif // EVENTMANAGER_H_
