#include "switch_io.h"
#include "../io_factory.h"
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
SwitchIO::~SwitchIO(){};
