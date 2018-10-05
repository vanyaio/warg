#IFNDEF FIELD_H
#DEFINE FIELD_H
#include "consts.h"

class Field{
public:
  cell* cells_arr[FIELD_SIZE][FIELD_SIZE];

  Field();
  void moveCells(cell* src, cell* dest);
  bool isFinished();
  void regen();
};

#ENDIF
