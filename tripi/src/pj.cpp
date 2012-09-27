#include "header.h"

class Pj {
public:
  int lives;
  Point points[5];
  void rotate(int dir);
  void skip(int dir);
  void set_coordinates(int x1,int y1,int z1);
};

void Pj::set_coordinates(int x, int y, int z){
  lives = z;
  points[0].set_point( x+3, y+sb-3 );
  points[1].set_point( x+sb-3, y+sb-3 );
  points[2].set_point( x+3, y+3 );
  points[3].set_point( x+sb-3, y+3 );  
}

void Pj::skip(int dir){
  for( int j = 0; j < 4; ++j ){
    if(dir==1) points[j].x += 10;
    if(dir==2) points[j].x -= 10;
    if(dir==3) points[j].y += 10;
    if(dir==4) points[j].y -= 10;
  }
}

void Pj::rotate(int dir){
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