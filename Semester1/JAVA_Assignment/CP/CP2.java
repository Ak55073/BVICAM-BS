import java.util.Scanner;

public class CP2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter Caesar Code: ");
        String inp = scan.nextLine();
        inp = inp.toUpperCase();
        System.out.print("Enter shift(negative value for left shift): ");
        int shift = scan.nextInt();
        StringBuilder plainText = new StringBuilder();
        for(int i=0;i<inp.length();i++){
            int ascii = inp.charAt(i);
            if (ascii>= 65 && ascii <=90) {
                ascii += shift;
                char plain;
                if (ascii < 65) {
                    plain = (char) (91 - (65 - ascii));
                } else if (ascii > 90) {
                    plain = (char) (64 + (ascii - 90));
                } else {
                    plain = (char) ascii;
                }
                plainText.append(plain);
            } else{
                char plain = (char) ascii;
                plainText.append(plain);
            }
        }
        System.out.println("Deciphered text: "+plainText);
    }
}
