class BP4{
	public static void main(String args[]){
		String content = "This is random text by Abhinav, for testing.";
		
		System.out.println("Original String: "+content);
		System.out.println("5th char: "+content.charAt(5));
		System.out.println("Length of String: "+content.length());
		System.out.println("Does String contain Abhinav: "+content.contains("Abhinav"));
		System.out.println("Is string equal to \"why not?\": "+content.equals("Why not?"));
		System.out.println("Index of comma: "+content.indexOf(","));
		String split[] = content.split(",");
		System.out.println("Split on comma: ["+split[0]+"] ["+split[1]+"]");
		System.out.println("UpperCase: "+content.toUpperCase());
	}
}