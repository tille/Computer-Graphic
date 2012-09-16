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

using namespace std;

//gluPerspective(45.0f,(GLfloat)250/(GLfloat)250,0.1f,100.0f);
//glOrtho(-2.0, 20.0, -2.0, 2.0, -2.0, 500.0);

float x2,y2,z2,center_x,center_y,center_z;
int n,n1,n2,edges;

#define flt_max 3.402823466e+38F
#define flt_min 1.175494351e-38F
#define SIZE 20000
#define SIZE_SCR 800
#define pb push_back

struct point{
  float x, y, z;
  point(){}
  point(float x1,float y1,float z1){
    x = x1, y = y1, z = z1;
  }
};

vector<point> points;
vector<point> proy;
vector<int> links[SIZE];

// Se llama cuando cambia el tamaño de la ventana
void reshape(GLsizei w, GLsizei h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 300.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void p_scale(int opt){
  for( int i = 0; i < points.size(); ++i ){
    if(!opt) points[i].x *= 1.01;
    else if(opt==1) points[i].y *= 1.01;
    else if(opt==2) points[i].z *= 0.994;
    else if(opt==3) points[i].x *= 0.994;
    else if(opt==4) points[i].y *= 0.994;
    else if(opt==5) points[i].z *= 1.01;
  }
}

void calc_center(){
  float max_center_init_x = flt_min;
  float max_center_init_y = flt_min;
  float max_center_init_z = flt_min;
  float min_center_init_x = flt_max;
  float min_center_init_y = flt_max;
  float min_center_init_z = flt_max;
  
  for( int i = 0; i < points.size(); ++i ){
    max_center_init_x = max( max_center_init_x, points[i].x );
    min_center_init_x = min( min_center_init_x, points[i].x );
    max_center_init_y = max( max_center_init_y, points[i].y );
    min_center_init_y = min( min_center_init_y, points[i].y );
    max_center_init_z = max( max_center_init_z, points[i].z );
    min_center_init_z = min( min_center_init_z, points[i].z );
  }
  
  center_x = min_center_init_x + ((max_center_init_x - min_center_init_x)/2);
  center_y = min_center_init_y + ((max_center_init_y - min_center_init_y)/2);
  center_z = min_center_init_z + ((max_center_init_z - min_center_init_z)/2);
}

void p_rotate2(int opt){
  calc_center();
  float c_x = center_x, c_y = center_y, c_z = center_z, p_y, p_x, p_z;
  
  for( int i = 0; i < points.size(); ++i ){
    points[i].x -= center_x;
    points[i].y -= center_y;
    points[i].z -= center_z;
  }
  
  for( int i = 0; i < points.size(); ++i ){
    p_y = points[i].y, p_z = points[i].z, p_x = points[i].x;
    if(!opt){
      points[i].y = p_y*cos(M_PI/360.0) - p_z*sin(M_PI/360.0);
      points[i].z = p_z*cos(M_PI/360.0) + p_y*sin(M_PI/360.0);      
    }else if(opt==1){
      points[i].x = p_x*cos(M_PI/360.0) - p_y*sin(M_PI/360.0);
      points[i].y = p_y*cos(M_PI/360.0) + p_x*sin(M_PI/360.0);
    }else if(opt==2){
      points[i].z = p_z*cos(M_PI/360.0) - p_x*sin(M_PI/360.0);
      points[i].x = p_x*cos(M_PI/360.0) + p_z*sin(M_PI/360.0);
    }
  }
  
  for( int i = 0; i < points.size(); ++i ){
    points[i].x += center_x;
    points[i].y += center_y;
    points[i].z += center_z;
  }
}

void p_translate(int opt){
  for( int i = 0; i < points.size(); ++i ){
    if(!opt) points[i].y += 8;
    else if(opt==1) points[i].y -= 8;
    else if(opt==2) points[i].x -= 8;
    else if(opt==3) points[i].x += 8;
    else if(opt==4) points[i].z -= 1;
    else if(opt==5) points[i].z += 1;  
  }
}

// Escucha cada tecla
void keyboard(unsigned char key, int x, int y) {
  if(key == 'q') p_scale(0);
  else if(key == 'w') p_scale(1);
  else if(key == 'e') p_scale(2);
  else if(key == 'a') p_scale(3);
  else if(key == 's') p_scale(4);
  else if(key == 'd') p_scale(5);
  else if(key == 'r') p_translate(4);
  else if(key == 'f') p_translate(5);
  else if(key == 'z') p_rotate2(0);
  else if(key == 'x') p_rotate2(1);
  else if(key == 'c') p_rotate2(2);
  glutPostRedisplay();
}

// Responder a los eventos de teclas especiales
void specialKeys(int key, int x, int y) {
  if(key == GLUT_KEY_UP) p_translate(0);
  if(key == GLUT_KEY_DOWN) p_translate(1);
  if(key == GLUT_KEY_LEFT) p_translate(2);  
  if(key == GLUT_KEY_RIGHT) p_translate(3);
  glutPostRedisplay();
}

// Poyecta cada punto
void proyection(){
  proy.clear();
  for( int i = 0; i < n; ++i ){
    float p_x = (points[i].x*100)/points[i].z;
    float p_y = (points[i].y*100)/points[i].z;
    proy.pb(point(p_x,p_y,0));
  }
}

// Dibuja la proyeccion de cada punto
void draw_proyection(){
  glColor3f(0.0f, 1.0f, 0.0f);
  for( int i = 0; i < n; ++i ){
    for( int j = 0; j < links[i].size(); ++j ){
      glBegin(GL_LINES);
        glVertex2f(proy[i].x, proy[i].y);
        glVertex2f(proy[links[i][j]].x, proy[links[i][j]].y);      
      glEnd();
    }
  }
}

// Ciclo infinito para renderizar
void display(void) {
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glClear( GL_COLOR_BUFFER_BIT );
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,SIZE_SCR,0,SIZE_SCR);
  
  proyection();
  draw_proyection();
  
  glutSwapBuffers();
}

// Entrada desde el archivo home.in
void input_polyline(){
  //freopen("input/sphere.in","r",stdin);
  cin >> n;
  for( int i = 1; i <= n; ++i ){
    cin >> x2 >> y2 >> z2;
    points.pb(point(x2,y2,z2));
  }
  cin >> edges;
  while(edges--){
    cin >> n1 >> n2;
    links[n1-1].pb(n2-1);
  }
}

int main (int argc, char** argv) {
  glutInit (&argc, argv);                       // Initialize GLUT.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set display mode.
  input_polyline();                             // reading from a file

  glutInitWindowPosition (50, 100);             // Set top-left display-window position.
  glutInitWindowSize (SIZE_SCR, 400);           // Set display-window width and height.
  glutCreateWindow ("Challenge4");              // Create display window.
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(keyboard);

  glutDisplayFunc (display);                    // Send graphics to display window.
  glutMainLoop();                               // Display everything and wait.
  return 0;
}