import javax.swing.*;
import java.awt.*;

public class Principal extends JFrame {

	BottonPanel bp ;
	
	
	public Principal() {
		bp = new BottonPanel() ;
		this.setLayout(new BorderLayout()) ;
		this.setSize(1100, 700) ;
		this.setLocationRelativeTo(null) ;
		this.setDefaultCloseOperation(EXIT_ON_CLOSE) ;
		this.setResizable(false) ;
		add(bp, BorderLayout.SOUTH) ;
	}
	
	
	
	public static void main (String args []){
		Principal principal = new Principal();
		principal.setVisible(true) ;
		
	}
}
