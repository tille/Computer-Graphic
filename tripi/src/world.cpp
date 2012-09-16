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
  cout << "hola mundo" << endl;
}