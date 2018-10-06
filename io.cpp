#include "io.h"


TextIO::TextIO(Field* _field_ptr){
  this->field_ptr = _field_ptr;
}

IO_TO_CONT_MSG TextIO::move(){
  if (this->field_ptr->isFinished())
    return this->handleFinish();

  this->printField();

  IO_TO_CONT_MSG res;

  if (this->SwitchIOrequested()){

  }

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
    std::cout << "YOU WIN! CONTINIE: Y\N \n";
    char c;
    std::cin >> c;
    if (c == 'y' || c == 'Y')
      res.new_game = true;
    return res;
}

bool TextIO::SwitchIOrequested(){
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
