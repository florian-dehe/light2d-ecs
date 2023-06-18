#ifndef SYSTEM_H
#define SYSTEM_H

namespace ecs {

class system {
protected:
  virtual void process();
};

}

#endif // !SYSTEM_H
