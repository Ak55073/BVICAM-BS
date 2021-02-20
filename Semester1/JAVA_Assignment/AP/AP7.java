import java.util.Scanner;

public class AP7{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter a sentence: ");
		String text = scan.nextLine();
		System.out.println("Reverse string: " + reverseWord(text));
	}
	
	private static String reverseWord(String data){
		String reverse = "",word = "";
		for(int i=0;i<data.length();i++){
			char a = data.charAt(i);
			int ASCII = (int) Character.toLowerCase(a);;
			if (ASCII >= 97 && ASCII <= 122){
				word = a + word;
			} else {
				if (word.length() > 0){
					reverse = reverse + word;
					word = "";
				}
				reverse = reverse + a;
			}
		}
		return reverse;
	}
}
