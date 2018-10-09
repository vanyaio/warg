#ifndef IO_H
#define IO_H

#include "io_cont_msg.h"
#include "stdlibs.h"
#include "field.h"

class IO{
public:
  Field* field_ptr;
  virtual IO_TO_CONT_MSG move() = 0;
  virtual ~IO();
};

#endif
