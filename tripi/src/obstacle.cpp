#include "header.h"

class Obstacle {
  public:
    int x, y, height, width;
    void set_obstacle(int x1, int y1);
};

void Obstacle::set_obstacle(int x1, int y1){
  x = x1;
  y = y1;
}