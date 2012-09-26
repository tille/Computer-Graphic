#include "header.h"
#include "world.cpp"

class Driver {
	public:
    World world;
    void move_pj(int pos);
    void rotate_world(int dir);
    void rotate_board(int dir);
    void world_init();
    bool collision(int x, int y);
};

void Driver::move_pj(int pos) {
  int x = world.tripi.posx, y = world.tripi.posy;
  if( pos == 1 ) if( !collision(x+1,y) ) x++;
  if( pos == 2 ) if( !collision(x-1,y) ) x--;
  if( pos == 3 ) if( !collision(x,y+1) ) y++;
  if( pos == 4 ) if( !collision(x,y-1) ) y--;
  world.tripi.posx = x;
  world.tripi.posy = y;
  world.tripi.skip();
}

void Driver::rotate_world(int dir){
  world.rotate(dir);
  world.tripi.rotate(dir);
}

void Driver::rotate_board(int dir){
  world.board_rotate(dir);
}

void Driver::world_init(){
  world.init();
}

bool Driver::collision(int x, int y){
  if( x < 0 || x>39 ) return true;
  if( world.board[x][39-y] == '1' ) return true;
  return false;
}