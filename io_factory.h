#ifndef IO_FACTORY_H
#define IO_FACTORY_H

#include "io_modes/colored_io.h"
#include "io_modes/switch_io.h"
#include "io_modes/text_io.h"

class IOfactory{
public:
  const static std::vector<std::string> IOlist;
  static IO* get_new_io_ptr(int new_io_num, Field* field_ptr);
};

#endif // IO_FACTORY_H
