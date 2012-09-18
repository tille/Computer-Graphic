#include "header.h"
#include "obstacle.cpp"
#include "hole.cpp"
#include "pj.cpp"

class World {
	public:
    int orientation;
    Pj tripi;
    vector<Obstacle> obstacles;
    vector<Hole> holes;
    void rotate();
    void init();
};

void World::rotate() {
}

void World::init() {
  freopen("input/1.in","r",stdin);
  string line;
  
  for( int j = 0; cin >> line; ++j ){
    for( int i = 0; i < line.size(); ++i ){
      if(line[i] == '1'){
        Obstacle temp;
        temp.set_obstacle(i,j);
        obstacles.pb(temp);
      }
    }
  }
  
  tripi.set_coordinates(0,0,3);
}