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
    g2d.setColor(Color.green);
    g2d.drawLine(left, top, right, top);
    g2d.drawLine(left, down, right, down);
    g2d.drawLine(left, down, left, top);
    g2d.drawLine(right, down, right, top);
  }
  
  boolean trivial_validations(Dimension p1, Dimension p2){
    if( p1.width < left  && p2.width < left  ||
        p1.width > right && p2.width > right ||
        p1.height < top  && p2.height < top  ||
        p1.height > down && p2.height > down ) return false;
    return true;
    
  }
  
  void add_lines(Graphics2D g2d){
    g2d.setColor(Color.red);
    
    for( int i = 0; i < 10; ++i ){
    
      Random rand = new Random();
      Dimension p1 = new Dimension(rand.nextInt(800),rand.nextInt(500));
      Dimension p2 = new Dimension(rand.nextInt(800),rand.nextInt(500));

      boolean outside = trivial_validations(p1,p2);
      if(outside) cohen_sutherland(p1,p2, g2d);
      else g2d.drawLine(p1.width, p1.height, p2.width, p2.height);
    }
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

    int x0 = pi.width;
    int x1 = pf.width;
    int y0 = pi.height;
    int y1 = pf.height;
    int x=0,y=0;
    
    if (i == 8) {
      x = (x0 + (down - y0) * (x1 - x0) / (y1 - y0));
      y = down;
    } else if (i == 4) {
      x = (x0 + (top - y0) * (x1 - x0) / (y1 - y0));
      y = top;
    } else if (i == 1) {
      x = left;
      y = (y0 + (y1 - y0) * (left - x0) / (x1 - x0));
    } else if (i == 2) {
      x = right;
      y = (y0 + (y1 - y0) * (right - x0) / (x1 - x0));
    }

    return new Dimension(x,y);
  }
  
  int find_position(Dimension p){
    if( p.width < left ) return 1;
    else if( p.width > right ) return 2;
    else if( p.height < top ) return 4;
    else if( p.height > down ) return 8;
    return 0;
  }
  
  Dimension step_up(Dimension pi, Dimension pf){
    int c1 = find_position(pi);
    Dimension result = new Dimension();
    
    for( int i = 1;; i*=2){
      if( (c1 & i) > 0 ){ 
        result = intersection(pi,pf,i);
        break;
      }
    }

    return result;
  }
  
  void cohen_sutherland(Dimension p1, Dimension p2, Graphics2D g2d){
    Dimension cpy1 = p1, cpy2 = p2;
    double total_dist = dist(p1,p2);
    int error = 0;
    
    while( ( not_is_inside(cpy1) || not_is_inside(cpy2) ) ){
      if( total_dist - (dist(p1,cpy1)+dist(p2,cpy2)) <= 0 ){ 
        error = 1;
        break;
      }
      
      if( not_is_inside(cpy1) ) cpy1 = step_up(cpy1,p2);
      if( not_is_inside(cpy2) ) cpy2 = step_up(cpy2,p1);
    }
    
    if( error == 1 ) g2d.drawLine(p1.width, p1.height, p2.width, p2.height);
    else{
      g2d.setColor(Color.red);
      g2d.drawLine(p1.width, p1.height, cpy1.width, cpy1.height);
      g2d.setColor(Color.blue);
      g2d.drawLine(cpy1.width, cpy1.height, cpy2.width, cpy2.height);
      g2d.setColor(Color.red);
      if(cpy2 != p2) g2d.drawLine(cpy2.width, cpy2.height, p2.width, p2.height);
    }
  }
  
  public static void main(String[] args) {
    JFrame frame = new JFrame("Cohen Sutherland Algorithm");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(new Cohen_sutherland());
    frame.setSize(800, 500);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);
    frame.setBackground(Color.black);
  }
}
