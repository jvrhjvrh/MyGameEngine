#ifndef ENTITY_H_
#define ENTITY_H_

#include <stdint.h>

struct Entity {
  uint32_t id;
  bool operator==(const Entity entity) const { return id == entity.id; }
};

#endif // ENTITY_H_
