#include "header.h"

class Pj {
public:
  int lives, posx, posy;
  Point points[5];
  void rotate(int dir);
  void skip();
  void set_coordinates(int x1,int y1,int z1);
};

void Pj::set_coordinates(int x, int y, int z){
  lives = z, posx = posy = 0;
  points[0].set_point( x, y+sb );
  points[1].set_point( x+sb, y+sb );
  points[2].set_point( x, y );
  points[3].set_point( x+sb, y );  
}

void Pj::skip(){
  points[0].set_point( posx*sb, posy*sb+sb );
  points[1].set_point( (posx*sb)+sb, (posy*sb)+sb );
  points[2].set_point( posx*sb, posy*sb );
  points[3].set_point( (posx*sb)+sb, (posy*sb) );    
}

void Pj::rotate(int dir){
  int temp_x = posx, temp_y = posy;
  if(!dir) posx = temp_y, posy = 39-temp_x;
  else posx = 39-temp_y, posy = temp_x;

  for( int j = 0; j < 4; ++j ){
    points[j].x -= 400;
    points[j].y -= 400;

    Point temp = points[j];
    if(!dir){
      points[j].x = temp.x*cos(M_PI/30.0) - temp.y*sin(M_PI/30.0);
      points[j].y = temp.y*cos(M_PI/30.0) + temp.x*sin(M_PI/30.0);
    }else{
      points[j].x = temp.x*cos(M_PI/30.0) + temp.y*sin(M_PI/30.0);
      points[j].y = temp.y*cos(M_PI/30.0) - temp.x*sin(M_PI/30.0);  
    }

    points[j].x += 400;
    points[j].y += 400;
  }
}