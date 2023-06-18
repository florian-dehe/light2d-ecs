#include "gtest/gtest.h"
#include <memory>

#include "component.hpp"
#include "entity.hpp"
#include "registry.hpp"
#include "test_component.hpp"

TEST(ComponentTest, CanCreateDummyComponent) {
  ecs::component comp = ecs::component();

  ASSERT_EQ(false, comp.is_attached());
}

TEST(ComponentTest, CanCreateComponent) {
  test_component comp = test_component(10, 3.4f);

  ASSERT_EQ(false, comp.is_attached());
  ASSERT_EQ(10, comp.get_a());
  ASSERT_EQ(3.4f, comp.get_b());
}

TEST(ComponentTest, CanAttachComponent) {
  ecs::registry reg = ecs::registry();
  ecs::entity ent = reg.create();

  std::shared_ptr<test_component> comp;
  comp = std::make_shared<test_component>(8, 4.3f);
  reg.attach(ent, comp);

  ASSERT_EQ(true, comp->is_attached());
}

TEST(ComponentTest, AttachedComponentInMemory) {
  ecs::registry reg = ecs::registry();
  ecs::entity ent = reg.create();

  std::shared_ptr<test_component> comp;
  comp = std::make_shared<test_component>(8, 4.3f);
  reg.attach(ent, comp);

  const ecs::entity_def &comps = reg.get(ent);

  ASSERT_EQ(1, comps.size());

  // Increase the use count
  std::shared_ptr<ecs::component> same_comp = comps.at(0);

  ASSERT_EQ(true, same_comp->is_attached());
  ASSERT_EQ(3, same_comp.use_count());
  ASSERT_EQ(comp.get(), same_comp.get());
}

TEST(ComponentTest, CanRemoveComponent) {
  ecs::registry reg = ecs::registry();
  ecs::entity ent = reg.create();

  std::shared_ptr<test_component> comp;
  comp = std::make_shared<test_component>(11, 3.5f);

  reg.attach(ent, comp);
  ASSERT_EQ(true, comp->is_attached());
  ASSERT_EQ(2, comp.use_count());

  reg.remove(ent, comp);
  ASSERT_EQ(false, comp->is_attached());
  ASSERT_EQ(1, comp.use_count());
}

TEST(ComponentTest, IsCompClearedWhenDestroyingEnt) {
  ecs::registry reg = ecs::registry();
  ecs::entity ent = reg.create();

  std::shared_ptr<test_component> comp;
  comp = std::make_shared<test_component>();

  reg.attach(ent, comp);
  ASSERT_EQ(true, comp->is_attached());
  ASSERT_EQ(2, comp.use_count());

  reg.destroy(ent);
  ASSERT_EQ(false, comp->is_attached());
  ASSERT_EQ(1, comp.use_count());
}
