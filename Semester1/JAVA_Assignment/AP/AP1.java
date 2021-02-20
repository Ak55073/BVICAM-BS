class AP1{
	public static void main(String[] args){
		if (args.length < 5){
			System.out.println("Minimum 5 input required.");
			return;
		}
		Sum ob = new Sum();
		System.out.println("AP.Sum="+ob.add(args));
	}
}

class Sum{
	int add(String[] args){
		return ( Integer.parseInt(args[0])
		+Integer.parseInt(args[1])
		+Integer.parseInt(args[2])
		+Integer.parseInt(args[3])
		+Integer.parseInt(args[4]) );
	}
}