#ifndef IO_H
#define IO_H
#include "io_cont_msg.h"

class IO{
public:
  Field* field_ptr;
  virtual IO_TO_CONT_MSG move() = 0;
  static IO* get_new_io_ptr(int new_io_num){

  }
};

class TextIo{
};

class IO_OPTIONS{
public:

};
#endif
