#IFNDEF IO_CONT_MSG_H
#DEFINE IO_CONT_MSG_H

class IO_TO_CONT_MSG{
public:
  int type;

  bool new_game;
  bool exit_game;

  cell* src;
  cell* dest;

  int new_io_num;
  IO_CONT_MSG();
}

#ENDIF
