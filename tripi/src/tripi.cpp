#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "driver.cpp"
#include "gravity.cpp"
#include "opengl.cpp"

int main (int argc, char** argv) {
  glutInit (&argc, argv);                       // Initialize GLUT.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set display mode.

  glutInitWindowPosition (50, 100);             // Set top-left display-window position.
  glutInitWindowSize (SIZE_SCR, SIZE_SCR2);      // Set display-window width and height.
  glutCreateWindow ("Tripi Adventures");        // Create display window.
  glutReshapeFunc(reshape);                     // Is called for resize the window
  glutSpecialFunc(specialKeys);                 // Driver for the specialKeys
  glutKeyboardFunc(keyboard);                   // Driver for the normal keys
  
  glutDisplayFunc (display);                    // Send graphics to display window.
  glutMainLoop();                               // Display everything and wait.
  return 0;
}