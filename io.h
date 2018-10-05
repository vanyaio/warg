#IFNDEF IO_H
#DEFINE IO_H
#include "io_cont_msg.h"

class IO{
public:
  Field* field_ptr;
  virtual IO_CONT_MSG move();

}

class IO_OPTIONS{
public:

}
#ENDIF
