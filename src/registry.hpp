#ifndef REGISTRY_H
#define REGISTRY_H

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <map>
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

#include "attachable.hpp"
#include "component.hpp"
#include "entity.hpp"
#include "system.hpp"

#define ENTITY_NOT_FOUND "entity not found"
#define COMP_NOT_FOUND "component not found"

namespace ecs {

typedef std::vector<std::shared_ptr<component>> entity_def;

class registry {
public:
  /* ===== Constr & Destr ===== */
  registry() {
    std::srand(std::time(nullptr)); // Randomize

    m_entities = std::map<entity, entity_def>();
    m_systems = std::vector<std::shared_ptr<system>>();
  }

  ~registry() { clear(); }

  void clear() {
    m_entities.clear();
    m_systems.clear();
  }

  /* ===== Entities ===== */
  entity create() {
    entity ent = -1;

    do {
      ent = std::rand();
    } while (m_entities.count(ent) > 0);

    if (ent != -1) {
      m_entities.insert(std::make_pair(ent, entity_def{}));
    }

    return ent;
  }

  bool exists(entity id) { return m_entities.count(id) > 0; }

  const entity_def &get(entity id) {
    if (!exists(id)) {
      throw std::runtime_error(ENTITY_NOT_FOUND);
    }
    return m_entities.at(id);
  }

  void destroy(entity id) {
    if (!exists(id)) {
      throw std::runtime_error(ENTITY_NOT_FOUND);
    }

    entity_def &comps = m_entities.at(id);
    for (std::shared_ptr<component> comp : comps) {
      comp->_set_attached(false);
    }
    comps.clear(); // Clear the shared_ptrs
    m_entities.erase(id);
  }

  /* ===== Components ===== */
  void attach(entity id, std::shared_ptr<component> comp) {
    if (!exists(id)) {
      throw std::runtime_error(ENTITY_NOT_FOUND);
    }
    entity_def &comps = m_entities.at(id);
    comps.push_back(comp);
    comp->_set_attached(true);
  }

  void remove(entity id, std::shared_ptr<component> comp) {
    // Remove this component to the list associated to the ent.
    if (!exists(id)) {
      throw std::runtime_error(ENTITY_NOT_FOUND);
    }

    entity_def &comps = m_entities.at(id);
    auto found = std::find(comps.begin(), comps.end(), comp);
    if (found != comps.end()) {
      (*found)->_set_attached(false);
      comps.erase(found);
    } else {
      throw std::runtime_error(COMP_NOT_FOUND);
    }
  }

  /* ===== Systems ===== */
  void attach(std::shared_ptr<system> sys);
  void remove(std::shared_ptr<system> sys);

  /* ===== Registry ===== */
  void start();

  bool is_running() { return m_running; }

  void stop() { m_running = false; }

private:
  std::map<entity, entity_def> m_entities;
  std::vector<std::shared_ptr<system>> m_systems;

  bool m_running = false;
};

} // namespace ecs

#endif // !REGISTRY_H
