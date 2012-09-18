#include "header.h"

class Pj {
	public:
    int x, y, lives;
    void set_coordinates(int x1,int y1,int z1);
};

void Pj::set_coordinates(int x1, int y1, int z1){
  x = x1;
  y = y1;
  lives = z1;
}