#ifndef SWITCH_IO_H
#define SWITCH_IO_H

#include "../io.h"

class SwitchIO : public IO{
public:
  SwitchIO(Field* _field_ptr);
  ~SwitchIO();

  IO_TO_CONT_MSG move();
};

#endif
