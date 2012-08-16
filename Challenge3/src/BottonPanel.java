import javax.swing.*;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class BottonPanel extends JPanel implements ActionListener {
	
	
	JButton rotate, translate, scalation,addpoint ;
	JTextField rAngle, translateX, translateY , scalateX, scalateY ;
	Transformaciones t ;
	ArrayList <int []> listaPuntos = new ArrayList();
	
	
	public BottonPanel(){
		this.setLayout(new GridLayout(1,11)) ;
		rotate = new JButton("ROTACION");
		rotate.setActionCommand("ROTATE") ;
		rotate.addActionListener(this) ;
		
		translate = new JButton("TRANSLATION");
		translate.setActionCommand("TRASLATE") ;
		translate.addActionListener(this) ;
		
		scalation = new JButton("SCALATE");
		scalation.setActionCommand("SCALATE") ;
		scalation.addActionListener(this) ;
		
		addpoint = new JButton("Add point") ;
		addpoint.setActionCommand("ADD") ;
		addpoint.addActionListener(this) ;
		
		rAngle = new JTextField();
		translateX = new JTextField();
		translateY = new JTextField();
		scalateX = new JTextField();
		scalateY = new JTextField();
		
		add(addpoint);
		add(translate) ;
		add(translateX) ;
		add(translateY) ;
		add(scalation) ;
		add(scalateX) ;
		add(scalateY) ;
		add(rotate) ;
		add(rAngle) ;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		String comando = e.getActionCommand() ;
		if (comando.equals("ROTATE")){
			
		}else if (comando.equals("TRANSLATE")) {
			
		}else if (comando.equals("SCALATE")){
			
		}else if (comando.equals("ADD")){
			int arr [] = new int [3] ;
			arr[0] = Integer.parseInt(JOptionPane.showInputDialog("Ingrese la coordenada en X"));
			arr[1] =Integer.parseInt(JOptionPane.showInputDialog("Ingrese la coordenada en Y"));
			arr[2] =1 ;
			this.listaPuntos.add(arr) ;
		}
	}

}
