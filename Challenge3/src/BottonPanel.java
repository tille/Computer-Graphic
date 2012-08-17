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
	Principal p;
	
	public BottonPanel(Principal p){
		this.p=p;
		this.setLayout(new GridLayout(1,11)) ;
		rotate = new JButton("ROTATION");
		rotate.setActionCommand("ROTATE") ;
		rotate.addActionListener(this) ;
		
		translate = new JButton("TRANSLATION");
		translate.setActionCommand("TRASLATE") ;
		translate.addActionListener(this) ;
		
		scalation = new JButton("SCALATION");
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
		add(scalation) ;
		add(rotate) ;
		add(rAngle) ;
	}
	
	

	@Override
	public void actionPerformed(ActionEvent e) {
		String comando = e.getActionCommand() ;
		if (comando.equals("ROTATE")){
			
		}else if (comando.equals("TRANSLATE")) {
			try {
				
				double x = Integer.parseInt(JOptionPane.showInputDialog("Ingrese el desplazamiento   X"));
				double y =Integer.parseInt(JOptionPane.showInputDialog("Ingrese el desplazamiento  Y"));
				t.setTranslate(true) ;
				for (int i = 0 ; i < this.listaPuntos.size() ; i ++ ){
					listaPuntos.set(i, t.transformar(this.listaPuntos.get(i), x, y));
				}
				p.paintEverything(listaPuntos) ;

			} catch (Exception exp){		
		}
			
		}else if (comando.equals("SCALATE")){
			try {
				double x = Integer.parseInt(JOptionPane.showInputDialog("Ingrese el escalamiento  X"));
				double y =Integer.parseInt(JOptionPane.showInputDialog("Ingrese el escalamiento Y"));
				this.t.setScalate(true) ;
				for (int i = 0 ;  i < this.listaPuntos.size() ; i++ ){
					listaPuntos.set(i, t.transformar(this.listaPuntos.get(i), x, y));
				}
				p.paintEverything(listaPuntos) ;

			}catch(Exception exep) {}
			
		}else if (comando.equals("ADD")){
			int arr [] = new int [3] ;
			try {
				arr[0] = Integer.parseInt(JOptionPane.showInputDialog("Ingrese la coordenada en X"));
				arr[1] =Integer.parseInt(JOptionPane.showInputDialog("Ingrese la coordenada en Y"));
			}catch(Exception ecep) {}
			arr[2] =1 ;
			this.listaPuntos.add(arr) ;
			p.paintEverything(listaPuntos) ;
			
		}
	}
}