public class AP6{
	public static void main(String[] args){
		BOX ob1 = new BOX(5,5,5);
		System.out.println("Volume of box1: "+ob1.volume());
		
		BOX ob2 = new BOX(7,12,4);
		System.out.println("Volume of box1: "+ob2.volume());
	}
}

class BOX{
	private int length,width,height;
	BOX(int length, int width, int height){
		this.length = length;
		this.width = width;
		this.height = height;
	}
	
	int volume(){
		return (length*width*height);
	}
}