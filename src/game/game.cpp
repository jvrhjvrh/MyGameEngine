#include "game.h"
#include "../entities/entityHandle.hpp"

Game::Game() {
  entityManager = std::unique_ptr<EntityManager>(new EntityManager());
}

EntityHandle Game::createEntity() {
  return {entityManager->createEntity(), this};
}
