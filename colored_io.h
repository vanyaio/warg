#ifndef COLORED_IO_H
#define COLORED_IO_H

#include "io.h"
class pixel
{
public:
  char sign;
  int color;
  pixel();
  pixel(char _sing, int _color);
};

class ColoredIO : public IO{
public:
  Cell** selected_cell;
  Cell** cursored_cell;
  clock_t last_key_pressed;
  pixel buff[FIELD_SIZE + 1][FIELD_SIZE + 1];

  ColoredIO(Field* _field_ptr);
  ~ColoredIO();

  IO_TO_CONT_MSG move();
  void print_field();

  int getKeyPressed();
  void moveCursor(int key_pressed);
  void selectCell(int key_pressed);

  bool switchIOrequested(int key_pressed);
  IO_TO_CONT_MSG handleSwitchIO();

  IO_TO_CONT_MSG moveChip(int key_pressed);
};


#endif // COLORED_IO_H
