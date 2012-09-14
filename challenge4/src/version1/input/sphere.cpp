#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

#define R 100

float m_y, y, z;

int main(){
  stack<int> q;
  int cont = 0;
  for( int x = 10; x < R; x = x+4 ){
    m_y = sqrt(R*R - x*x);
    y = -m_y+1;
    while( y < m_y ){
      z = sqrt( R*R - x*x - y*y );
      if(z){
        q.push(z);
        q.push(y);
        q.push(x);
        q.push(-z);
        q.push(y);
        q.push(x);
        cont += 2;
      }
      y += 14;
    } 
  }
  
  cout << cont << endl;
  for( int i = 0; i < q.size(); ++i ){
    cout << q.top()+100 << " ";  q.pop();
    cout << q.top()+100 << " ";  q.pop();
    cout << q.top()+100 << endl; q.pop();
  }

  cout << (cont*(cont-1))/2 << endl;
  for( int i = 1; i <= cont; ++i ){
    for( int j = i+1; j <= cont; ++j ){
      printf("%d %d\n", i,j);
    }
  }
  return 0;
}