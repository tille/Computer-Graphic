Driver d;
Gravity g;

void reshape(GLsizei w, GLsizei h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void draw(){

  int sb = 20; // size_block
  glColor3f(0.0f, 1.0f, 0.0f);
  for( int i = 0; i < d.world.obstacles.size(); ++i ){
    int px = d.world.obstacles[i].x, j = d.world.obstacles[i].y;
    
    glBegin(GL_LINES);
      glVertex2f(px*sb, SIZE_SCR2-(j*sb));
      glVertex2f((px+1)*sb, SIZE_SCR2-(j*sb));
    glEnd();
    glBegin(GL_LINES);
      glVertex2f(px*sb, SIZE_SCR2-((j+1)*sb));
      glVertex2f((px+1)*sb, SIZE_SCR2-((j+1)*sb));
    glEnd();
    glBegin(GL_LINES);
      glVertex2f(px*sb, SIZE_SCR2-(j*sb));
      glVertex2f(px*sb, SIZE_SCR2-((j+1)*sb));
    glEnd();
    glBegin(GL_LINES);
      glVertex2f((px+1)*sb, SIZE_SCR2-(j*sb));
      glVertex2f((px+1)*sb, SIZE_SCR2-((j+1)*sb));
    glEnd();
  }
  
  glColor3f(.5f, .5f, .5f);
  int px = d.world.tripi.x, j = d.world.tripi.y;
  glBegin(GL_LINES);
    glVertex2f(px*sb, (j*sb));
    glVertex2f((px+1)*sb, (j*sb));
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(px*sb, ((j+1)*sb));
    glVertex2f((px+1)*sb, ((j+1)*sb));
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(px*sb, (j*sb));
    glVertex2f(px*sb, ((j+1)*sb));
  glEnd();
  glBegin(GL_LINES);
    glVertex2f((px+1)*sb, (j*sb));
    glVertex2f((px+1)*sb, ((j+1)*sb));
  glEnd();
  
}

void keyboard(unsigned char key, int x, int y) {
  if(key == 'q') d.world_init();
  glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
  //if(key == GLUT_KEY_UP) p_translate(0);
  //if(key == GLUT_KEY_DOWN) p_translate(1);
  if(key == GLUT_KEY_LEFT) d.move_pj(2);  
  if(key == GLUT_KEY_RIGHT) d.move_pj(1);
  glutPostRedisplay();
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