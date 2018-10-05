#IFNDEF CONTROLLER_H
#DEFINE CONTROLLER_H
#include "field.h"
#include "io.h"

class Controller{
public:
  Field* field_ptr;
  IO* io_ptr;
  Contoller();
  void mainCirc();
};

#ENDIF
