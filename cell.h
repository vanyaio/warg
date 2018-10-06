#ifndef CELL_H
#define CELL_H
#include "stdlibs.h"

class Cell{
public:
  bool chip;
  bool free_space;
  bool blocked_space;
  int color;

  int x;
  int y;

  Cell();

  bool isAdjacentWith(Cell* cell_ptr);
};
#endif // CELL_H
