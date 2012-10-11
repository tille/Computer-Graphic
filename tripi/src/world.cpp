#include "header.h"
#include "obstacle.cpp"
#include "hole.cpp"
#include "pj.cpp"

#define SIZE_B 45

class World {
	public:
    int orientation;
    Pj tripi;
    vector<Obstacle> obstacles;
    vector<Hole> holes;
    void rotate(int dir);
    void init();
};

void World::rotate(int dir) {
  for( int i = 0; i < obstacles.size(); ++i ){
    for( int j = 0; j < 4; ++j ){
      obstacles[i].points[j].x -= 400;
      obstacles[i].points[j].y -= 400;
      
      Point temp = obstacles[i].points[j];
      
      if(!dir){
        obstacles[i].points[j].x = temp.x*cos(M_PI/30.0) - temp.y*sin(M_PI/30.0);
        obstacles[i].points[j].y = temp.y*cos(M_PI/30.0) + temp.x*sin(M_PI/30.0);
      }else{
        obstacles[i].points[j].x = temp.x*cos(M_PI/30.0) + temp.y*sin(M_PI/30.0);
        obstacles[i].points[j].y = temp.y*cos(M_PI/30.0) - temp.x*sin(M_PI/30.0);  
      }
        
      obstacles[i].points[j].x += 400;
      obstacles[i].points[j].y += 400;
    }
  }
}

void World::init() {
  freopen("input/2.in","r",stdin);
  string line;
  
  for( int j = 0; cin >> line; ++j ){
    for( int i = 0; i < line.size(); ++i ){
      if(line[i] == '1'){
        Obstacle temp;
        temp.set_obstacle(i,j+1);
        obstacles.pb(temp);
      }
    }
  }
  
  tripi.set_coordinates(0,0,3);
}