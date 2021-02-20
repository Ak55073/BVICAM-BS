class AP3{
	public static void main(String[] args){
		int_byte();
		double_int();
		double_byte();
		int_char();
		float_short();
	}
	
	private static void int_byte(){
		//INT to Byte
		int a = 132;
		System.out.print("INT: "+a);
		byte b = (byte) a;
		System.out.println(" to Byte: "+b);
	}
	
	private static void double_int(){
		//Double to INT
		double a = 132.8568;
		System.out.print("Double: "+a);
		int b = (int) a;
		System.out.println(" to INT: "+b);
	}
	
	private static void double_byte(){
		//Double to Byte
		double a = 132.856;
		System.out.print("Double: "+a);
		byte b = (byte) a;
		System.out.println(" to Byte: "+b);
	}
	
	private static void int_char(){
		//INT to Char
		int a = 65;
		System.out.print("INT: "+a);
		char b = (char) a;
		System.out.println(" to Char: "+b);
	}
	
	private static void float_short(){
		//Float to Short
		float a = 98765.56789f;
		System.out.print("Float: "+a);
		short b = (short) a;
		System.out.println(" to Short: "+b);
	}
}