#ifndef COLORED_IO_H
#define COLORED_IO_H

#include "io.h"

class ColoredIO : public IO{
public:
  Cell* selected_cell;
  Cell* cursored_cell;

  pixel buff[FIELD_SIZE + 1][FIELD_SIZE + 1];

  ColoredIO(Field* _field_ptr);

  IO_TO_CONT_MSG move();
  void print_field();

  int getKeyPressed();
  void moveCursor(int key_pressed);
  void selectCell(int key_pressed);

  bool switchIOrequested(int key_pressed);
  IO_TO_CONT_MSG handleSwitchIO();

  void moveChip(int key_pressed);
};

class pixel
{
public:
  char sign;
  int color;
  pixel();
  pixel(char _sing, int _color);
};

#endif // COLORED_IO_H
