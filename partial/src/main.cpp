#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct point {
  double x, y, z;
  point(){}
  point(double x, double y, double z) : x(x), y(y), z(z) {}
};

vector< vector< point > > points;
vector< vector<int> > C;

inline double bez(int n, int i, double u) {
  double res = C[n][i] * pow(u, i) * pow(1.0 - u, n - i);
  return res;
}

point P(double u, double v) {
  int n = points.size();
  int m = points[0].size();

  point res;
  res.x = res.y = res.z = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      double temp = bez(n - 1, i, u) * bez(m - 1, j, v);
      res.x += temp * points[i][j].x;
      res.y += temp * points[i][j].y;
      res.z += temp * points[i][j].z;
    }
  }
  return res;
}

void binomial() {
  int n = max(points.size(), points[0].size());
  
  C.assign(n + 1, vector<int>(n + 1, 0) );
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i){
    for (int j = 0; j <= n; ++j) {
      C[i][j] = C[i-1][j];
      if (j > 0) C[i][j] += C[i-1][j-1];
    }
  }
}

void input(char * name_file) {
  int n, m;
  points.clear();
  
  ifstream file(name_file);  
  file >> n >> m;
  
  for (int i = 0; i < n; ++i) {
    points.push_back( vector<point>() );
    for (int j = 0; j < m; ++j) {
      double x, y, z;
      file >> x >> y >> z;
      points.back().push_back( point(x, y, z) );
    }
  }
}

void bezier_u(double u) {
  glBegin(GL_LINES);    
    double inc = 0.1;
    for (double v = 0.0; v < 1.0 - inc; v += inc) {
      point p1 = P(u, v);
      point p2 = P(u, v + inc);       
      glVertex3f(p1.x, p1.y, p1.z);
      glVertex3f(p2.x, p2.y, p2.z);

      // triangles
      point p3 = P(u+0.1, v + inc);
      if(u+inc < 1.0){
        glVertex3f(p1.x, p1.y, p1.z);
        glVertex3f(p3.x, p3.y, p3.z);
      }
    }
  glEnd();    
}

void bezier_v(double v) {
  glBegin(GL_LINES);    
    double inc = 0.01;
    for (double u = 0.0; u < 1.0 - inc; u += inc) {
      point p1 = P(u, v);
      point p2 = P(u + inc, v);
      glVertex3f(p1.x, p1.y, p1.z);
      glVertex3f(p2.x, p2.y, p2.z);
    }
  glEnd();   
}

void bezier_surface(){  
  glColor3f(0, 1, 1);
  for (double u = 0; u <= 1.0; u += 0.1) bezier_u(u);
  for (double v = 0; v <= 1.0; v += 0.1) bezier_v(v);
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  gluLookAt(0, 0, 100,  0, 0, 0,   0, 1, 0);
  glRotatef(45.0/2,  1, 0, 0);
  glRotatef(-45.0/2,  0, 1, 0);  
  
  bezier_surface();
  glutSwapBuffers();
}

void reshape(int newWidth, int newHeight){
  glViewport(0, 0, newWidth, newHeight);  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
}

void initializeGlut(){
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void valid(int argc){
  if (argc < 2){
    cout << "Ingrese un archivo de texto como argumento." << endl;
    exit(0);
  }
}

int main(int argc, char **argv) {
  valid(argc);
  input(argv[1]);
  binomial();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Superficies de Bezier");
  glutDisplayFunc(display);    
  glutReshapeFunc(reshape);
  initializeGlut();
  glutMainLoop();
  return 0;
}
