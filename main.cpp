#include "stdlibs.h"
#include "field.h"

int main()
{
  srand(time(NULL));
  Field f;
  f.regen();

  for (int i = 0; i < FIELD_SIZE; i++){
    for (int j = 0; j < FIELD_SIZE; j++)
    {
      /*std::cout << f.cells_arr[i][j]->x << " " << f.cells_arr[i][j]->y << ": ";
      if (f.cells_arr[i][j]->chip)
        std::cout << "Chip: " << f.cells_arr[i][j]->color << std::endl;
      if (f.cells_arr[i][j]->blocked_space)
        std::cout << "Blocked\n";
      if (f.cells_arr[i][j]->free_space)
        std::cout << "FREE\n";*/
      std::cout << f.cells_arr[i][j]->chip << "(" << f.cells_arr[i][j]->x << "," << f.cells_arr[i][j]->y << ")";
      std::cout << "(" << i << "," << j << ")";
      std::cout << f.cells_arr[i][j] << " " << &f.cells_arr[i][j] << "   ";
    }
    std::cout << "\n";
  }

  int x0, y0, x1, y1;
  std::cin >> x0 >> y0 >> x1 >> y1;
  f.moveCells(f.cells_arr[x0][y0], f.cells_arr[x1][y1]);

  for (int i = 0; i < FIELD_SIZE; i++){
    for (int j = 0; j < FIELD_SIZE; j++)
    {
      /*std::cout << f.cells_arr[i][j]->x << " " << f.cells_arr[i][j]->y << ": ";
      if (f.cells_arr[i][j]->chip)
        std::cout << "Chip: " << f.cells_arr[i][j]->color << std::endl;
      if (f.cells_arr[i][j]->blocked_space)
        std::cout << "Blocked\n";
      if (f.cells_arr[i][j]->free_space)
        std::cout << "FREE\n";*/
      std::cout << f.cells_arr[i][j]->chip << "(" << f.cells_arr[i][j]->x << "," << f.cells_arr[i][j]->y << ")";
      std::cout << "(" << i << "," << j << ")";
      std::cout << f.cells_arr[i][j] << " " << &f.cells_arr[i][j] << "   "                                        ;
    }
    std::cout << "\n";
  }
}
