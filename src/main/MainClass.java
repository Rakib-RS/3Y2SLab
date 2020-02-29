package main;

public class MainClass {
	public String  triangle(int x ,int y ,int z) {
		if(x>99||y>99 || z>99 || x<1 || y<1 || z<1)
			return "invalid input";
		else if(x==y&&x==z)
			return "EQUILATERAL";
		else if(x==y || y == z || x==z)
			return "ISOSCELENES" ;
		else if(x!=y && x!= z && y!=z)
			return "SCELENE";
		else 
			return "IVALID INPUT";
		//return null;
			
	}

}
