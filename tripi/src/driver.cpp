#include "header.h"
#include "world.cpp"

class Driver {
	public:
    World world;
    void move_pj(int pos);
    void rotate_world();
    void world_init();
    bool collision(int x, int y);
};

void Driver::move_pj(int pos) {
  int x = world.tripi.x, y = world.tripi.y;
  if( pos == 1 ) if( !collision(x+1,y) ) x++;
  if( pos == 2 ) if( !collision(x-1,y) ) x--;
  world.tripi.x = x;
}

void Driver::rotate_world(){
}

void Driver::world_init(){
  world.init();
}

bool Driver::collision(int x, int y){
  if( x < 0 || x>39 ) return true;
  for( int i = 0; i < world.obstacles.size(); ++i ){
    int px = world.obstacles[i].x, j = world.obstacles[i].y;
    if( px == x && y == 39-j ) return true;
  }
  return false;
}