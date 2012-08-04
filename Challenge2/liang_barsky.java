import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;

import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.util.Random;

public class BresenhamJorman extends JPanel {

  public static int w, h, c;
  static int skip = 5 ;

  public void set_screen_size() {
    Dimension size = getSize();
    Insets insets = getInsets();
    w = size.width - insets.left - insets.right;
    h = size.height - insets.top - insets.bottom;
    c = getSize().width;
  }
  
  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    Graphics2D g2d = (Graphics2D) g;
    set_screen_size();
    
    Dimension p1 = new Dimension(0,0);
    Dimension p2 = new Dimension(c,0);
	g2d.setColor(Color.green);
   
    //int skip = 5;
    for( int i = 0; i < w; i+=skip ){
    	g2d.setColor(Color.blue);
      p1.setSize(i,0);
      p2.setSize(w,i);
      //bresenham_line(p1,p2,g2d);
      this.LiangBarsky(200, 300, 0, 0, i, 0, w, i, g2d);

      g2d.setColor(Color.red);
      p1.setSize(w,i);
      p2.setSize(w-i,h);
      //bresenham_line(p1,p2,g2d);
      this.LiangBarsky(200, 300, 0, 0, w, i, w-i, h, g2d);
      
      g2d.setColor(Color.black);
      p1.setSize(w-i,h);
      p2.setSize(0,h-i);
      //bresenham_line(p1,p2,g2d);
      
      g2d.setColor(Color.orange);
      p1.setSize(0,h-i);
      p2.setSize(i,0);
      //bresenham_line(p1,p2,g2d);
    }
  }

  public static int LiangBarsky (int Xmax ,int Ymax , int Xmin , int Ymin, int x0 ,int y0 , int x1, int y1,Graphics g2d ){
	  
	  int deltax = (x1-x0);
	  int deltay = (y1-y0) ;
	  int u0 = 0 ;
	  int u1 = 1;
	    


	  //calculate the values of pk
	  int p [] = new int [5] ;
	   p[1] = -deltax ;
	   p[2] = deltax ;
	   p[3] = -deltay ;
	   p[4] = deltay ;
	  
	   
	   //calculates the values of qk
	  int q [] = new int [5] ;
	  q[1] = x0 - Xmin ;
	  q[2] = Xmax -x0 ;
	  q[3] = y0 - Ymin ;
	  q[4] = Ymax -y0 ;
	  
	
	  
	  //Checking for parallel lines
	  for (int i = 1 ; i <= 4 ; i++){
		  if (p[i]==0){
			  if (q[i] < 0){
				  return 0 ;
			  }
		  }
	  }
	  
	  int r [] = new int [5];
	  for (int i = 1 ; i <= 4 ; i++) {
		 try {
		  r[i] = q[i] / p[i] ;
		 }catch (Exception e) {
			 
		 }
	  }
	  // calculating u0 and u1
	 for (int i = 1  ; i <=4 ; i++){
		 if (p [i]< 0){
			 if (r [i] > u0){
				 u0 = r[i] ;
			 }
		 }else if (p [i] > 0) {
			 if (r [i] < u1){
				 u1 = r[i] ;
			 }
		 }
	 }
	 x0 = x0 + u0 *(deltax) ;
	 y0 = y0 + u0 *(deltay) ;
	 x1 = x0 + u1 *(deltax) ;
	 y1 = y0 + u1 * (deltay) ;
	 
	 g2d.drawLine(x0, y0, x1, y1);
	return 0;
	  
	  
  }
  public static void bresenham_line(Dimension p1, Dimension p2, Graphics g2d) {
    
    int y1 = (int) p2.getHeight(), 
        y0 = (int) p1.getHeight(), 
        x1 = (int) p2.getWidth(), 
        x0 = (int) p1.getWidth(),
        dx =  x1 - x0, 
        dy =  y1 - y0,
        y = y0,
        x = x0, 
        incE, incNE, d, stepx, stepy;
    
    if (dy < 0){ dy = -dy; stepy = -1; 
    }else stepy = 1;
    
    if (dx < 0){ dx = -dx; stepx = -1; 
    }else stepx = 1;
    
    if( dx > dy ){
      incE = 2*dy;
      incNE = 2*dy - 2*dx;
      d = 2*dy - dx;
      
      for( ;x != x1; x+=stepx ){
        g2d.drawLine(x,-(y-h),x,-(y-h));
        if( d < 0 ) d += incE;
        else{
          d += incNE;
          y+=stepy;
        }
      }
    }else{
      incE = 2*dx;
      incNE = 2*dx - 2*dy;
      d = 2*dx - dy;
      
      for( ;y != y1; y+=stepy ){
        g2d.drawLine(x,-(y-h),x,-(y-h));
        if( d < 0 ) d += incE;
        else{
          d += incNE;
          x+=stepx;
        }
      }
    }
  }

  public static void main(String[] args) {
    JFrame frame = new JFrame("Points");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    int x =Integer.parseInt(JOptionPane.showInputDialog("Ingrese el incremento en X y Y " + " este debe ser un numero entre 0-100"));
	setskip(x);
    frame.add(new BresenhamJorman());
    frame.setSize(800, 800);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);
  }

  private static void setskip(int x) {
	skip = x ;
  }
}