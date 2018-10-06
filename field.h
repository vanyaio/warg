#ifndef FIELD_H
#define FIELD_H

#include "consts.h"
#include "cell.h"

class Field{
public:
  Cell* cells_arr[FIELD_SIZE][FIELD_SIZE];

  Field();
  void moveCells(Cell*& src, Cell*& dest);
  bool isFinished();
  void regen();
  void placeCell(Cell* cell);
};

#endif
