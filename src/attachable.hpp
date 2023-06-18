#ifndef ATTACHABLE_H
#define ATTACHABLE_H

namespace ecs {

class attachable {
public:
  bool is_attached() { return m_attached; }
  void _set_attached(bool value) { m_attached = value; }
private:
  bool m_attached = false;
};

}

#endif // !ATTACHABLE_H

