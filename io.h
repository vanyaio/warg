#ifndef IO_H
#define IO_H

#include "io_cont_msg.h"
#include "stdlibs.h"
#include "field.h"

class IO{
public:
  Field* field_ptr;
  virtual IO_TO_CONT_MSG move() = 0;
};

class TextIO : public IO{
public:
  TextIO(Field* _field_ptr);

  IO_TO_CONT_MSG move();
  IO_TO_CONT_MSG handleFinish();
  bool SwitchIOrequested();
  void printField();
  bool isMoveInCorrect(int arr[]);
};

class SwitchIO : public IO{
public:
  SwitchIO(Field* _field_ptr);

  IO_TO_CONT_MSG move();
};
class IOfactory{
public:
  const static std::vector<std::string> IOlist;
  static IO* get_new_io_ptr(int new_io_num, Field* field_ptr);
};
#endif
