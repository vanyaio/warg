#include "io.h"


IO_TO_CONT_MSG SwitchIO::move(){
    IO_TO_CONT_MSG res;
    std::cout << "Available graphical modes:\n";
    for (int i = 0; i < IOfactory::IOlist.size(); i++)
      std::cout << i << ". " << IOfactory::IOlist[i] << std::endl;

    std::cout << "Type number:\n";
    int new_io_num;
    std::cin >> new_io_num;

    res.type = CHANGE_IO;
    res.new_io_num = new_io_num;
    return res;
}
SwitchIO::SwitchIO(Field* _field_ptr){
  this->field_ptr = _field_ptr;
}







TextIO::TextIO(Field* _field_ptr){
  this->field_ptr = _field_ptr;
}

IO_TO_CONT_MSG TextIO::move(){
  if (this->field_ptr->isFinished())
    return this->handleFinish();

  this->printField();

  IO_TO_CONT_MSG res;

  if (this->SwitchIOrequested()){
    std::cout << "Available graphical modes:\n";
    for (int i = 0; i < IOfactory::IOlist.size(); i++)
      std::cout << i << ". " << IOfactory::IOlist[i] << std::endl;

    std::cout << "Type number:\n";
    int new_io_num;
    std::cin >> new_io_num;

    res.type = CHANGE_IO;
    res.new_io_num = new_io_num;
    return res;
  }

  std::cout << "Type your move: \n";
  int coord[4];
  std::cin >> coord[0] >> coord[1] >> coord[2] >> coord[3];
  if (!this->isMoveInCorrect(coord)){
    std::cout << "Not Correct Input\n";
    return res;
  }
  res.type = MOVE;
  res.src = &(this->field_ptr->cells_arr[coord[0]][coord[1]]);
  res.dest = &(this->field_ptr->cells_arr[coord[2]][coord[3]]);
  return res;
}

IO_TO_CONT_MSG TextIO::handleFinish(){
    IO_TO_CONT_MSG res;
    res.type = GAME_FINISHED;
    std::cout << "YOU WIN! CONTINIE: Y or N \n";
    char c;
    std::cin >> c;
    if (c == 'y' || c == 'Y')
      res.new_game = true;
    return res;
}

bool TextIO::SwitchIOrequested(){
  std::cout << "Switch or Move?\n";
  char c;
  std::cin >> c;
  if (c == 's' || c == 'S')
    return true;
  return false;
}
void TextIO::printField(){
  std::cout << "  ";
  for (int y = 0; y < FIELD_SIZE; y++)
    std::cout << y << " ";
  std::cout << std::endl;

  for (int x = 0; x < FIELD_SIZE; x++){
    std::cout << x << " ";
    for (int y = 0; y < FIELD_SIZE; y++){
        Cell* cell = this->field_ptr->cells_arr[x][y];
        if (cell->blocked_space)
          std::cout << "B";
        if (cell->free_space)
          std::cout << "F";
        if (cell->chip)
          std::cout << cell->color;
        std::cout << " ";
    }
    std::cout << std::endl;
  }
}

bool TextIO::isMoveInCorrect(int arr[]){
  for (int i = 0; i < 4; i++)
    if (arr[i] >= FIELD_SIZE || arr[i] < 0)
      return false;
  return true;
}










const std::vector<std::string> IOfactory :: IOlist({"Switch menu", "Plain text", "Colored text"});
IO* IOfactory::get_new_io_ptr(int new_io_num, Field* field_ptr)
{
  switch (new_io_num)
  {
    case 0:
      return new SwitchIO(field_ptr);
      break;
    case 1:
      return new TextIO(field_ptr);
      break;
    case 2:
      return new ColoredIO(field_ptr);
      break;
    default:
      return new TextIO(field_ptr);
  }
}
