#ifndef TEST_COMPONENT_H
#define TEST_COMPONENT_H

#include "component.hpp"

class test_component : public ecs::component {
public:
  test_component() {}
  test_component(int a, float b) : m_property_a(a), m_property_b(b) {}

  int get_a() { return m_property_a; }
  float get_b() { return m_property_b; }

  void set_a(int a) { m_property_a = a; }
  void set_b(float b) { m_property_b = b; }

private:
  int m_property_a;
  float m_property_b;
};


#endif // !TEST_COMPONENT_H

