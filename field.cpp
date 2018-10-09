#include "field.h"
#include "consts.h"

Field::Field(){
  for (int i = 0; i < FIELD_SIZE; i++)
    for (int j = 0; j < FIELD_SIZE; j++)
      this->cells_arr[i][j] = nullptr;
}

void Field::regen()
{

  for (int i = 0; i < FIELD_SIZE; i++)
    for (int j = 0; j < FIELD_SIZE; j++)
      if (this->cells_arr[i][j] != nullptr){
        delete this->cells_arr[i][j];
        this->cells_arr[i][j] = nullptr;
      }

  for (int x = 0; x < FIELD_SIZE; x +=2)
    for (int y = 1; y < FIELD_SIZE; y += 2)
    {
      Cell* tmp = new Cell;
      tmp->blocked_space = true;
      tmp->x = x;
      tmp->y = y;
      this->cells_arr[x][y] = tmp;
    }

  for (int color = 0; color < COLORS_AMOUNT; color++)
    for (int chip_of_the_color = 0; chip_of_the_color < CHIPS_OF_THE_COLOR; chip_of_the_color++)
    {
      Cell* tmp = new Cell;
      tmp->chip = true;
      tmp->color = color;
      this->placeCell(tmp);
    }

  for (int free_space = 0; free_space < FREE_SPACE_AMOUNT; free_space++)
  {
    Cell* tmp = new Cell;
    tmp->free_space = true;
    this->placeCell(tmp);
  }
}

void Field::placeCell(Cell* cell)
{
  while (true){
    int x = rand() % FIELD_SIZE, y = rand() % FIELD_SIZE;
    if (cells_arr[x][y] != nullptr)
      continue;
    cells_arr[x][y] = cell;
    cell->x = x;
    cell->y = y;
    break;
  }
}

bool Field::isFinished(){
  int colors[COLORS_AMOUNT];
  std::fill(colors, colors + COLORS_AMOUNT, 0);

  for (int y = 0, color = 0; y < FIELD_SIZE; y += 2, color++)
    for (int x = 0; x < FIELD_SIZE; x++)
      if (cells_arr[x][y]->color == color)
        colors[color]++;

  for (int color = 0; color < COLORS_AMOUNT; color++)
    if (colors[color] != CHIPS_OF_THE_COLOR)
      return false;
  return true;
}

void Field::moveCells(Cell*& src, Cell*& dest){
  if (!src->isAdjacentWith(dest))
    return;
  if (src->chip && dest->free_space)
  {
    std::swap(src, dest);
    std::swap(src->x, dest->x);
    std::swap(src->y, dest->y);
  }
  return;
}
