#include "header.h"
#include "obstacle.cpp"
#include "hole.cpp"
#include "pj.cpp"

#define SIZE_B 45

class World {
	public:
    int orientation;
    char board[SIZE_B][SIZE_B];
    Pj tripi;
    vector<Obstacle> obstacles;
    vector<Hole> holes;
    void rotate(int dir);
    void init();
    void board_rotate(int dir);
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

void World::board_rotate(int dir){
  if(!dir){
    char board_temp[SIZE_B][SIZE_B];
    for(int i=0;i<40;++i) for(int j=0;j<40;++j) board_temp[39-j][i] = board[i][j];
    for(int i=0;i<40;++i) for(int j=0;j<40;++j) board[i][j] = board_temp[i][j];
  }else{
    char board_temp[SIZE_B][SIZE_B];
    for(int i=0;i<40;++i) for(int j=0;j<40;++j) board_temp[j][39-i] = board[i][j];
    for(int i=0;i<40;++i) for(int j=0;j<40;++j) board[i][j] = board_temp[i][j];
  }
}

void World::init() {
  freopen("input/1.in","r",stdin);
  string line;
  
  for( int j = 0; cin >> line; ++j ){
    for( int i = 0; i < line.size(); ++i ){
      board[i][j] = line[i];
      if(line[i] == '1'){
        Obstacle temp;
        temp.set_obstacle(i,j+1);
        obstacles.pb(temp);
      }
    }
  }
  
  tripi.set_coordinates(0,0,3);
}