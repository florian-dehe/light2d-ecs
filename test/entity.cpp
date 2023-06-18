#include "gtest/gtest.h"

#include "entity.hpp"
#include "registry.hpp"

TEST(EntityTest, CanCreateEntity) {
  ecs::registry reg = ecs::registry();
  ecs::entity ent =  reg.create();

  ASSERT_EQ(true, reg.exists(ent));
}

TEST(EntityTest, CanGetEntity) {
  ecs::registry reg = ecs::registry();
  ecs::entity ent =  reg.create();

  const ecs::entity_def &comps = reg.get(ent);

  // Should be created with zero components
  ASSERT_EQ(0, comps.size());
}

TEST(EntityTest, CanDestroyEntity) {
  ecs::registry reg = ecs::registry();
  ecs::entity ent =  reg.create();
  
  ASSERT_EQ(true, reg.exists(ent));

  reg.destroy(ent);

  ASSERT_EQ(false, reg.exists(ent));
}

TEST(EntityTest, EntityIdIsRandom) {
  ecs::registry reg = ecs::registry();
  
  ecs::entity ent =  reg.create();
  ecs::entity new_ent = reg.create();

  ASSERT_NE(ent, new_ent);
}


