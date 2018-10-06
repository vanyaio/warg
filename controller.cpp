#include "controller.h"

Controller::Controller(){
  this->field_ptr = new Field;
  this->io_ptr = new TextIO(field_ptr);
}

void Controller::mainCirc(){
  this->field_ptr->regen();

  while (true){
    IO_TO_CONT_MSG msg = this->io_ptr->move();

    if (msg.type == MOVE){
      field_ptr->moveCells(*msg.src, *msg.dest);
      /*std::cout << "_______________\n";
      std::cout << msg.src->x << " " << msg.src->y << std::endl;
      std::cout << msg.dest->x << " " << msg.dest->y << std::endl;*/
    }

    if (msg.type == CHANGE_IO){
      IO* temp = this->io_ptr->get_new_io_ptr(msg.new_io_num);//NEED TO PASS field pointer here
      delete io_ptr;
      io_ptr = temp;
    }

    if (msg.type == GAME_FINISHED){
      if (msg.new_game)
        this->field_ptr->regen();
      else
        return;
    }
  }
}
