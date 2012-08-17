public class Transformaciones {

	private boolean rotate , translate , scalate ;
	
	//Getters and Setters methods
	public void setRotate (boolean x ){rotate = x ;}
	public boolean getRotate(){return rotate ;}
	public void setTranslate (boolean x ){translate = x ;}
	public boolean getTranslate(){return translate ;}
	public void setScalate (boolean x ){scalate = x ;}
	public boolean getScalate(){return scalate ;}
	
	
	public int [] transformar(int a [] ,double x , double y ){
		if(translate){
			a [0] += Math.round(x) ;
			a [1] += Math.round(y) ;
			translate = false ;
			return a ;
		}
		if (scalate){
			a [0] =(int) Math.round(x * a [0])  ;
			a [1] = (int) Math.round(y * a [1]) ;
			scalate = false ;
			return a ;
		}
		return a ;
	}
	
	public int [] transformar (int a [] , double angle){
		a [0] = (int) Math.round(a[0] *Math.cos(angle) - (a[1] * Math.sin(angle))) ;
		a [1] = (int) Math.round(a[0] *Math.sin(angle) + (a[1] * Math.cos(angle))) ;
		return a ;
	}
}