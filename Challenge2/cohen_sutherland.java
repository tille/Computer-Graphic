package cohen_sutherland;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.util.Random;
import java.math.*;

public class Cohen_sutherland extends JPanel {

  public static int w, h, c, left = 200, right = 600, down = 350, top = 100;
  
  public void set_screen_size() {
    Dimension size = getSize();
    Insets insets = getInsets();
    w = size.width - insets.left - insets.right;
    h = size.height - insets.top - insets.bottom;
  }
  
  public void draw_clipping_area(Graphics2D g2d){
    g2d.setColor(Color.black);
    g2d.drawLine(left, top, right, top);
    g2d.drawLine(left, down, right, down);
    g2d.drawLine(left, down, left, top);
    g2d.drawLine(right, down, right, top);
  }
  
  void add_lines(Graphics2D g2d){
    // La idea esque esto no quede quemado y pueda haber 
    // una interfaz para agregar nuevas lineas.
    Dimension p1 = new Dimension(50,250);
    Dimension p2 = new Dimension(350,250);
    g2d.setColor(Color.red);
    //g2d.drawLine(p1.width, p1.height, p2.width, p2.height);
    
    /*boolean outside = trivial_validations(p1,p2);
    if(outside == false) cohen_sutherland(p1,p2, g2d);
    else g2d.drawLine(p1.width, p1.height, p2.width, p2.height);*/
    
    cohen_sutherland(p1,p2, g2d);
  }
  
  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    Graphics2D g2d = (Graphics2D) g;
    set_screen_size();
    draw_clipping_area(g2d);
    add_lines(g2d);
  }
  
  double dist(Dimension p1, Dimension p2){
    double x = p1.width - p2.width;
    if( x < 0 ) x = -x;
    double y = p1.height - p2.height;
    if( y < 0 ) y = -y;
    return Math.sqrt(x*x + y*y);
  }
  
  boolean not_is_inside(Dimension p){
    if( p.width < left || p.width > right || p.height < top || p.height > down ) return true;
    else return false;
  }
  
  Dimension intersection(Dimension pi, Dimension pf, int i){
    int x01=0, x11=0, x02=0, x12=0, y01=0, y11=0, y02=0, y12=0;
    
    x01 = pi.width;
    x11 = pf.width;
    y01 = pi.height;
    y11 = pf.height;
   
    if( i == 1 ){ 
      x02 = left; 
      y02 = -1;
      x12 = left; 
      y12 = 502;
    }else if( i == 2 ){
      x02 = right;
      y02 = -1;
      x12 = right; 
      y12 = 502;
    }
    
    double num = (x01-x02-y01+y02)*(y12-y02);
    double den = ((y11+y01)-(x11-x01))*(x12-x02);
    double t1 = num/den;
    
    double x2 = left;
    double x = x01+(t1*(x11-x01));
    double y = y01+(t1*(y11-y01));
    double y2 = (y01 + (y11 - y01) * (left - x01) / (x11 - x01));
    
    
    Dimension cosa = new Dimension((int)x2,(int)y2);
    return cosa;
  }
  
  int find_position(Dimension p){
    if( p.width < left ) return 1;
    else if ( p.width > right ) return 2;
    return 0;
  }
  
  Dimension step_up(Dimension pi, Dimension pf){
    int c1 = find_position(pi);
    Dimension result = new Dimension(-360,-1);
    
    for( int i = 1; result.width == -360; i*=2){
      if( (c1 & i) > 0 ) result = intersection(pi,pf,i);
          //System.out.println(".. "+pi.width);
    }

    return result;
  }
  
  void cohen_sutherland(Dimension p1, Dimension p2, Graphics2D g2d){
    Dimension cpy1 = p1, cpy2 = p2;
    double total_dist = dist(p1,p2);
    int error = 0,cont = 0;
    
    while( ( not_is_inside(cpy1) || not_is_inside(cpy2) ) ){
      if( total_dist - (dist(p1,cpy1)+dist(p2,cpy2)) <= 0 ){ 
        error = 1;
        break;
      }
      
      if( not_is_inside(cpy1) ){ 
        /*if( cont < 2 ){
          //System.out.println("x- "+cpy1.width);
          //System.out.println("y- "+cpy1.height);
          cont++;
        }*/
        cpy1 = step_up(cpy1,p2);
      }
      if( not_is_inside(cpy2) ){ 
        //System.out.println("cpy2");
        cpy2 = step_up(cpy2,p1);
      }
    }
    
    if( error == 1 ) g2d.drawLine(p1.width, p1.height, p2.width, p2.height);
    else{
      g2d.drawLine(p1.width, p1.height, cpy1.width, cpy1.height);
      g2d.setColor(Color.blue);
      g2d.drawLine(cpy1.width, cpy1.height, cpy2.width, cpy2.height);
      g2d.setColor(Color.black);
      g2d.drawLine(cpy2.width, cpy2.height, p2.width, p2.height);
    }
  }
  
  public static void main(String[] args) {
    JFrame frame = new JFrame("Points");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(new Cohen_sutherland());
    frame.setSize(800, 500);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);    
  }
}
