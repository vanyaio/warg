#ifndef TEXT_IO_H
#define TEXT_IO_H

#include "../io.h"

class TextIO : public IO{
public:
  TextIO(Field* _field_ptr);
  ~TextIO();

  IO_TO_CONT_MSG move();
  IO_TO_CONT_MSG handleFinish();
  bool SwitchIOrequested();
  void printField();
  bool isMoveInCorrect(int arr[]);
};
#endif // TEXT_IO_H
