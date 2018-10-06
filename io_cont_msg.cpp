#include "io_cont_msg.h"

IO_TO_CONT_MSG::IO_TO_CONT_MSG(){
  type = -1;
  new_game = exit_game = false;
  src = dest = nullptr;
  new_io_num = -1;
}
