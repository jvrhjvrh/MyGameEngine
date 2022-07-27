#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include "entity.h"
#include <stdint.h>

class EntityManager {
public:
  Entity createEntity();
  void destroy(Entity entity);

private:
  uint32_t lastEntity = 0;
};

#endif // ENTITYMANAGER_H_
