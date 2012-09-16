#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

#include "operations.h"

using namespace std;

#define SIZE_SCR 800

// Se llama cuando cambia el tamaño de la ventana
void reshape(GLsizei w, GLsizei h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// Escucha cada tecla
void keyboard(unsigned char key, int x, int y) {
  //if(key == 'q') p_scale(0);
  glutPostRedisplay();
}

// Responder a los eventos de teclas especiales
void specialKeys(int key, int x, int y) {
  //if(key == GLUT_KEY_UP) p_translate(0);
  //if(key == GLUT_KEY_DOWN) p_translate(1);
  //if(key == GLUT_KEY_LEFT) p_translate(2);  
  //if(key == GLUT_KEY_RIGHT) p_translate(3);
  glutPostRedisplay();
}

// Ciclo infinito para renderizar
void display(void) {
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glClear( GL_COLOR_BUFFER_BIT );
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,SIZE_SCR,0,SIZE_SCR);
  
  glutSwapBuffers();
}

int main (int argc, char** argv) {
  glutInit (&argc, argv);                       // Initialize GLUT.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set display mode.

  glutInitWindowPosition (50, 100);             // Set top-left display-window position.
  glutInitWindowSize (SIZE_SCR, 400);           // Set display-window width and height.
  glutCreateWindow ("Tripi Adventures");        // Create display window.
  glutReshapeFunc(reshape);                     // Is called for resize the window
  glutSpecialFunc(specialKeys);                 // Driver for the specialKeys
  glutKeyboardFunc(keyboard);                   // Driver for the normal keys

  glutDisplayFunc (display);                    // Send graphics to display window.
  glutMainLoop();                               // Display everything and wait.
  return 0;
}