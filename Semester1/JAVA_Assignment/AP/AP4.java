class AP4 {
	public static void main(String[] args) {
		String text = "To be or not to be, that is the question;"
		+"Whether this nobler in the mind to suffer"
		+" the slings and arrows of outrageous fortune,"
		+" or to take arms against a sea of troubles,"
		+" and by opposing end them?";

		int spaces = 0, vowels = 0, letters = 0;
		text = text.toLowerCase();
		
		for(int i=0;i<text.length();i++){
			
			char a = text.charAt(i);
			if (a == ' '){
				spaces++;
			} else if("aeiou".indexOf(a) >= 0){
				vowels++;
			} 
			
			int ASCII = (int) a;
			if (ASCII >= 97 && ASCII <= 122){
				letters++;
			}
		}
		System.out.println("The text contained vowels: " + vowels 
		+ "\nconsonants: " + (letters - vowels) + " (letters - vowels) " + "\n"+ "spaces: " + spaces);
	}
}
