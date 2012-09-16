void reshape(GLsizei w, GLsizei h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
  //if(key == 'q') p_scale(0);
  glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
  //if(key == GLUT_KEY_UP) p_translate(0);
  //if(key == GLUT_KEY_DOWN) p_translate(1);
  //if(key == GLUT_KEY_LEFT) p_translate(2);  
  //if(key == GLUT_KEY_RIGHT) p_translate(3);
  glutPostRedisplay();
}

void display(void) {
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glClear( GL_COLOR_BUFFER_BIT );
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,SIZE_SCR,0,SIZE_SCR);
  
  glutSwapBuffers();
}