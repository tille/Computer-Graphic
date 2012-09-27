#include "header.h"
#include "world.cpp"

class Driver {
public:
  World world;
  void move_pj(int pos);
  void rotate_world(int dir);
  void rotate_board(int dir);
  void world_init();
  bool collision(int dir);
};

void Driver::move_pj(int pos) {
  if(pos==1 && !collision(1)) world.tripi.skip(1);
  if(pos==2 && !collision(2)) world.tripi.skip(2);  
  if(pos==3 && !collision(3)) world.tripi.skip(3);
  if(pos==4 && !collision(4)) world.tripi.skip(4);  
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

bool Driver::collision(int dir){
  Point p[4];
  for( int i = 0; i < 4; ++i ) p[i] = world.tripi.points[i];
  if(dir==1) for( int i = 0; i < 4; ++i ) p[i].x += 10;
  if(dir==2) for( int i = 0; i < 4; ++i ) p[i].x -= 10;
  if(dir==3) for( int i = 0; i < 4; ++i ) p[i].y += 10;
  if(dir==4) for( int i = 0; i < 4; ++i ) p[i].y -= 10;

  for( int i = 0; i < 4; ++i ){ 
    if( p[i].x < 0 || p[i].x>40*sb ) return true;
    if( p[i].y < 0 || p[i].y>40*sb ) return true;
  }
  
  for( int i = 0; i < world.obstacles.size(); ++i ){
    double m_x = 10e5, g_x = -1, m_y = 10e5, g_y = -1;
    for( int j = 0; j < 4; ++j ){
      m_x = min(m_x,world.obstacles[i].points[j].x);
      g_x = max(g_x,world.obstacles[i].points[j].x);
      m_y = min(m_y,world.obstacles[i].points[j].y);
      g_y = max(g_y,world.obstacles[i].points[j].y);
    }
    
    for( int j=0; j<4; ++j ){
      if( p[j].x>=m_x && p[j].x<=g_x && p[j].y>=m_y && p[j].y<=g_y){
        return true;
      }
    }
  }
  return false;
}