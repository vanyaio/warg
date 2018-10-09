#include "io_factory.h"
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
