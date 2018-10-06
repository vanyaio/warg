#include "cell.h"

Cell::Cell()
{
  x = y = color = -1;
  chip = blocked_space = free_space = false;
}

bool Cell::isAdjacentWith(Cell* cell)
{
  int dx = abs(this->x - cell->x);
  int dy = abs(this->y - cell->y);

  if (std::min(dx, dy) == 0 && std::max(dx, dy) == 1)
    return true;
  return false;
}
