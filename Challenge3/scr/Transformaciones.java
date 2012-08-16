
public class Transformaciones {

	public  int [] translate(int a [], double deltax ,double deltay){
		a [0] += Math.round(deltax) ;
		a [1] += Math.round(deltay) ;
		return a ;
	}
	
	public int [] scalate (int a [] , int x , int y){
		a [0] *=Math.round(x * a [0])  ;
		a [1] *= Math.round(y * a [1]) ;
		return a ;
	}
	
	public int [] rotation(int a [] , double angle){
		a [0] = (int) Math.round(a[0] *Math.cos(angle) - (a[1] * Math.sin(angle))) ;
		a [1] = (int) Math.round(a[0] *Math.sin(angle) + (a[1] * Math.cos(angle))) ;
		return a ;
	} 
	

}
