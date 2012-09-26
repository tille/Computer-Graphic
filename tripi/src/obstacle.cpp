#include "header.h"
#include "point.cpp"

class Obstacle {
  public:
    Point points[5]; 
    void set_obstacle(double x, double y);
};

void Obstacle::set_obstacle(double x, double y){
  double x1, x2, x3, x4, y1, y2, y3, y4;
  x1 = x3 = x*sb;
  y1 = y2 = SIZE_SCR2-(y*sb);
  x2 = x4 = x1+sb;
  y3 = y4 = y1+sb;
  points[0].set_point( x1, y1 );
  points[1].set_point( x2, y2 );
  points[2].set_point( x3, y3 );
  points[3].set_point( x4, y4 );  
}