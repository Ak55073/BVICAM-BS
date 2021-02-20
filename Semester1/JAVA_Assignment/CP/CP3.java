import java.util.Scanner;

public class CP3 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter a text: ");
        String inp = scan.nextLine();

        int size = inp.length() - 1;
        for (int i = 0; i < inp.length() / 2; i++) {
            if (inp.charAt(i) != inp.charAt(size - i)) {
                System.out.println("String is not palindrome.");
                return;
            }
        }
        System.out.println("String is palindrome.");
    }
}
