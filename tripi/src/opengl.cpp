Driver d;
int turn_r = 0, turn_l = 0, right_press = 0, fall = 0;
double vel;

void draw_square(Point p1, Point p2, Point p3, Point p4){
  glBegin(GL_LINES);
  glVertex2f(p1.x, p1.y);
  glVertex2f(p2.x, p2.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(p2.x, p2.y);
  glVertex2f(p4.x, p4.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(p1.x, p1.y);
  glVertex2f(p3.x, p3.y);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(p3.x, p3.y);
  glVertex2f(p4.x, p4.y);
  glEnd();
}

void physic(){
  if(right_press) vel += 0.3;
}

void draw(){
  physic();
  
  glColor3f(0.0f, 1.0f, 0.0f);
  for( int i = 0; i < d.world.obstacles.size(); ++i ){
    Point p1 = d.world.obstacles[i].points[0], 
      p2 = d.world.obstacles[i].points[1],
      p3 = d.world.obstacles[i].points[2], 
      p4 = d.world.obstacles[i].points[3];
    draw_square(p1,p2,p3,p4);
  }

  glColor3f(.5f, .5f, .5f);
  Point p1 = d.world.tripi.points[0], 
    p2 = d.world.tripi.points[1],
    p3 = d.world.tripi.points[2], 
    p4 = d.world.tripi.points[3];
  draw_square(p1,p2,p3,p4);  
}

void keyboard(unsigned char key, int x, int y) {
  if(key == 't') d.world_init();
  if(key == 'd' && !turn_r) turn_r = 1;
  if(key == 'a' && !turn_l) turn_l = 1;
  
  glutPostRedisplay();
}

void animate(){
  if(fall){
    if(!d.collision(4)){
      d.world.tripi.skip(4);
      glutPostRedisplay();
      for( int i=0; i < 1000; ++i ) for( int j = 0; j < 10000; ++j ){}
    }else fall = 0;
  }
  
  if(turn_r){
    d.rotate_world(1);
    glutPostRedisplay();
    for( int i=0; i < 1000; ++i ) for( int j = 0; j < 10000; ++j ){}
    turn_r++;
    turn_r %= 16;
    if(!turn_r) fall = 1;
  }

  if(turn_l){
    d.rotate_world(0);
    glutPostRedisplay();
    for( int i=0; i < 1000; ++i ) for( int j = 0; j < 10000; ++j ){}
    turn_l++;
    turn_l %= 16;
    if(!turn_l) if(!d.collision(4)) fall = 1;
  }
}

void specialKeys(int key, int x, int y) {
  if(key == GLUT_KEY_UP && !turn_l && !turn_r) d.move_pj(3);
  if(key == GLUT_KEY_DOWN && !turn_l && !turn_r) d.move_pj(4);
  if(key == GLUT_KEY_LEFT && !turn_l && !turn_r) d.move_pj(2);
  if(key == GLUT_KEY_RIGHT && !turn_l && !turn_r){ 
    right_press = 1;
    d.move_pj(1);
  }
  
  if(!d.collision(4)) fall = 1;
  glutPostRedisplay();
}

void specialKeys_up(int key, int x, int y) {
  if(key == GLUT_KEY_RIGHT && !turn_l && !turn_r){ 
    cout << vel << endl;
    right_press = vel = 0;
  }
  glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void display(void) {
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glClear( GL_COLOR_BUFFER_BIT );
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,SIZE_SCR,0,SIZE_SCR2);
  draw();

  glutSwapBuffers();
}