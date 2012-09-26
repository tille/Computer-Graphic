#include "header.h"

class Point {
  public:
    double x,y;
    void set_point(double x1, double y1);
};

void Point::set_point(double x1, double y1){
  x = x1, y = y1;
}