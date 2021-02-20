import java.util.InputMismatchException;
import java.util.Scanner;

public class CP9 {
    public static void main(String[] args) {
        try {
            throwDemonstration();
        } catch (InputMismatchException exception) {
            System.out.println(". Input can't be decimal");
        }
    }

    static void throwDemonstration() throws InputMismatchException{
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number[1-10]: ");
        int inp = scan.nextInt();
        System.out.println(inp);
    }
}
