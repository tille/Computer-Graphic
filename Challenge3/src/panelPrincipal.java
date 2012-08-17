import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

import javax.swing.*;
public class panelPrincipal extends JPanel {
	
	
	BufferedImage im ;
	int contador = 0 ;
	
	public panelPrincipal(){
	
		im = new BufferedImage(Toolkit.getDefaultToolkit().getScreenSize().width -55, 
	    		Toolkit.getDefaultToolkit().getScreenSize().height - 80 , BufferedImage.BITMASK);
		
	}
	
	
	public void refrescar (){
		repaint();
	}

	public void paintEverything(ArrayList<int[]> listaPuntos) {
		Graphics2D g2d = (Graphics2D)im.getGraphics();
		g2d.setColor(Color.RED) ;
		for (int i = 1; i <listaPuntos.size(); i++) {
			g2d.drawLine(listaPuntos.get(i-1)[0], listaPuntos.get(i-1)[1], listaPuntos.get(i)[0], listaPuntos.get(i)[1]) ;
		}
		repaint();
	}
	
	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.drawImage(im,0,0,null);
	}
	
}
