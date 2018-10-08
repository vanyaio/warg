#include "colored_io.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void print(int x, int y, pixel& _img)
{
    std::swap(x, y);
    COORD c1;
    c1.X = x;
    c1.Y = y;

    SetConsoleCursorPosition(hConsole, c1);
    SetConsoleTextAttribute(hConsole, _img.color);
    std::cout << _img.sign;
}




ColoredIO::ColoredIO(Field* _field_ptr)
{
  this->field_ptr = _field_ptr;
  this->cursored_cell = &(this->field_ptr->cells_arr[0][0]);
  this->selected_cell = nullptr;
  this->last_key_pressed = clock();
  system("cls");
}
ColoredIO::~ColoredIO()
{
  SetConsoleTextAttribute(hConsole, 1);
  system("cls");
}

void ColoredIO::print_field()
{
  for (int i = 0; i < FIELD_SIZE; i++)
    for (int j = 0; j < FIELD_SIZE; j++)
    {
      Cell* curr_ptr = this->field_ptr->cells_arr[i][j];

      int curr_color;
      char curr_sign = ' ';
      if (curr_ptr->chip)
      {
        curr_sign = 'o';
        if (this->selected_cell == (&this->field_ptr->cells_arr[i][j]))
        {
          switch (curr_ptr->color)
          {
          case RED:
            curr_color = RED_SELECTED;
            break;
          case GREEN:
            curr_color = GREEN_SELECTED;
            break;
          case BLUE:
            curr_color = BLUE_SELECTED;
            break;
          }
        }
        else
        {
          switch (curr_ptr->color)
          {
          case RED:
            curr_color = RED_IO;
            break;
          case GREEN:
            curr_color = GREEN_IO;
            break;
          case BLUE:
            curr_color = BLUE_IO;
            break;
          }
        }
      }

      if (curr_ptr->blocked_space)
        curr_color = BLOCKED_COLOR;
      if (curr_ptr->free_space)
        curr_color = FREE_COLOR;

      pixel curr_pixel(curr_sign, curr_color);

      if (curr_pixel.color != this->buff[i][j].color
      || curr_pixel.sign != this->buff[i][j].sign)
      {
        print(i, j, curr_pixel);
        this->buff[i][j] = curr_pixel;
      }
    }


    if (this->selected_cell != nullptr)
    {

    }


    int y_buff_cursor = -1;
    for (int y = 0; y < FIELD_SIZE; y++)
      if (this->buff[FIELD_SIZE][y].sign == '^')
        y_buff_cursor = y;

    int x_buff_cursor = -1;
    for (int x = 0; x < FIELD_SIZE; x++)
      if (this->buff[x][FIELD_SIZE].sign == '<')
        x_buff_cursor = x;

    pixel empty_pixel(' ', 0);
    if ((*this->cursored_cell)->x != x_buff_cursor)
    {
      if (x_buff_cursor != -1){
        print(x_buff_cursor, FIELD_SIZE, empty_pixel);
        this->buff[x_buff_cursor][FIELD_SIZE] = empty_pixel;
      }

      pixel _pix1('<', 100);
      print((*this->cursored_cell)->x, FIELD_SIZE, _pix1);
      this->buff[(*this->cursored_cell)->x][FIELD_SIZE] = _pix1;
    }

    if ((*this->cursored_cell)->y != y_buff_cursor)
    {
      if (y_buff_cursor != -1){
        print(FIELD_SIZE, y_buff_cursor, empty_pixel);
        this->buff[FIELD_SIZE][y_buff_cursor] = empty_pixel;
      }

      pixel _pix('^', 100);
      print(FIELD_SIZE, (*this->cursored_cell)->y, _pix);
      this->buff[FIELD_SIZE][(*this->cursored_cell)->y] = _pix;
    }
}

int ColoredIO::getKeyPressed()
{
  std::vector<int> keys;
  keys.push_back(VK_RIGHT);
  keys.push_back(VK_UP);
  keys.push_back(VK_DOWN);
  keys.push_back(VK_LEFT);
  keys.push_back(S_KEY);
  keys.push_back(C_KEY);

  for (auto i : keys)
    if (GetAsyncKeyState(i) & 0x8000){
      this->last_key_pressed = clock();
      return i;
    }
  return -1;
}

IO_TO_CONT_MSG ColoredIO::move()
{
  this->print_field();
  if (((double)(clock() - last_key_pressed) / CLOCKS_PER_SEC) < 0.3)
  {
    IO_TO_CONT_MSG msg;
    return msg;
  }
  int key_pressed = this->getKeyPressed();

  bool switch_io_requested = this->switchIOrequested(key_pressed);
  if (switch_io_requested)
    return this->handleSwitchIO();

  if (this->selected_cell == nullptr)
  {
    this->moveCursor(key_pressed);
    this->selectCell(key_pressed);
    IO_TO_CONT_MSG empty_msg;
    return empty_msg;
  }
  else
    return this->moveChip(key_pressed);

}

bool ColoredIO::switchIOrequested(int key_pressed)
{
  if (key_pressed == S_KEY)
    return true;
  return false;
}
IO_TO_CONT_MSG ColoredIO::handleSwitchIO()
{
  system("cls");
  IO_TO_CONT_MSG res;
  res.type = CHANGE_IO;
  res.new_io_num = 0;
  return res;
}
void ColoredIO::moveCursor(int key_pressed)
{
  int dx = 0, dy = 0;
  switch (key_pressed)
  {
    case VK_UP:
      dx--;
      break;
    case VK_RIGHT:
      dy++;
      break;
    case VK_DOWN:
      dx++;
      break;
    case VK_LEFT:
      dy--;
      break;
    default:
      return;
  }

  if (this->cursored_cell != nullptr)
  {
    int curr_x = (*this->cursored_cell)->x, curr_y = (*this->cursored_cell)->y;
    int new_x = dx + curr_x, new_y = dy + curr_y;
    if (!((new_x >= 0 && new_x <FIELD_SIZE) && (new_y >= 0 && new_y <FIELD_SIZE)))
      return;
    this->cursored_cell = &(this->field_ptr->cells_arr[new_x][new_y]);
  }
}
void ColoredIO::selectCell(int key_pressed)
{
  if (key_pressed == C_KEY)
    this->selected_cell = this->cursored_cell;
}

IO_TO_CONT_MSG ColoredIO::moveChip(int key_pressed)
{
  IO_TO_CONT_MSG res;

  if (key_pressed == C_KEY)
  {
    this->selected_cell = nullptr;
    return res;
  }


  int dx = 0, dy = 0;
  switch (key_pressed)
  {
    case VK_UP:
      dx--;
      break;
    case VK_RIGHT:
      dy++;
      break;
    case VK_DOWN:
      dx++;
      break;
    case VK_LEFT:
      dy--;
      break;
  }

  if (dx == 0 && dy == 0)
    return res;

  int curr_x = (*this->selected_cell)->x, curr_y = (*this->selected_cell)->y;
  int move_x = dx + curr_x, move_y = dy + curr_y;

  if (!((move_x >= 0 && move_x < FIELD_SIZE) && (move_y >= 0 && move_y < FIELD_SIZE)))
    return res;

  res.type = MOVE;
  res.src = this->selected_cell;
  res.dest = &(this->field_ptr->cells_arr[move_x][move_y]);
  this->selected_cell = nullptr;
  return res;
}




pixel::pixel()
{
    sign = ' ';
    color = -1;
};

pixel::pixel(char _sign, int _color)
{
    sign = _sign;
    color = _color;
}

