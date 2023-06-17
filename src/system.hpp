#ifndef SYSTEM_H
#define SYSTEM_H

#include "component.hpp"

namespace ecs {

  class system {
  protected:
    virtual void process(const component &comp);
  };

}

#endif // !SYSTEM_H
