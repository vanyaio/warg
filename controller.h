#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "field.h"
#include "io.h"

class Controller{
public:
  Field* field_ptr;
  IO* io_ptr;
  Controller();
  void mainCirc();
};

#endif
