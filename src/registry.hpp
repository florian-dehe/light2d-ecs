#ifndef REGISTRY_H
#define REGISTRY_H

#include <cstdint>
#include <map>
#include <unordered_set>
#include <vector>

#include "entity.hpp"
#include "component.hpp"
#include "system.hpp"

namespace ecs {
  class registry {
  private:
    std::map<entity, std::vector<component>> m_entities;
    std::map<entity, bool> m_visibles;
    std::unordered_set<system> m_systems;
  public:
    registry();
    ~registry();

    // entity
    entity create();
    void set_visible(entity id, bool visible);
    void destroy(entity id);

    // components
    void attach(entity id, const component &comp);
    void remove(entity id, const component &comp);

    // systems
    void attach(const system &sys);
    void remove(const system &sys);

    // registry 
    void start();
    void stop();
  };
}

#endif // !REGISTRY_H
