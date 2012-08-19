import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Principal extends JFrame {

  BottonPanel bp ;
  panelPrincipal pp ;

  public Principal() {
    bp = new BottonPanel(this) ;
    pp = new panelPrincipal();
    this.setLayout(new BorderLayout()) ;
    this.setSize(Toolkit.getDefaultToolkit().getScreenSize().width - 50, 
    		Toolkit.getDefaultToolkit().getScreenSize().height - 50) ;
    this.setLocationRelativeTo(null) ;
    this.setDefaultCloseOperation(EXIT_ON_CLOSE) ;
    this.setResizable(true);
    add(bp, BorderLayout.SOUTH) ;
    add(pp , BorderLayout.CENTER) ;
  }

  public static void main (String args []){
    Principal principal = new Principal();
    principal.setVisible(true) ;
  }

public void paintEverything(ArrayList<int[]> listaPuntos, boolean reset) {
	pp.paintEverything(listaPuntos , reset);
	
}
}
