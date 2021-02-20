import java.util.Scanner;
import java.util.regex.Pattern;

class InvalidNumeralException extends Exception {
    @Override
    public String toString() {
        return "Only integer input expected.";
    }
}

public class CP8 {
    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(System.in);
            boolean flag = true;
            while (flag) {
                System.out.print("\nSelect\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit: ");
                int inp = scan.nextInt();
                scan.nextLine();

                System.out.print("Enter num1: ");
                String num1 = scan.nextLine();
                if (!Pattern.matches("\\d*", num1)) {
                    throw new InvalidNumeralException();
                }

                System.out.print("Enter num2: ");
                String num2 = scan.nextLine();
                if (!Pattern.matches("\\d*", num2)) {
                    throw new InvalidNumeralException();
                }

                switch (inp) {
                    case 1:
                        System.out.println("Addition: " + (Integer.parseInt(num1) + Integer.parseInt(num2)));
                        break;
                    case 2:
                        System.out.println("Subtraction: " + (Integer.parseInt(num1) - Integer.parseInt(num2)));
                        break;
                    case 3:
                        System.out.println("Multiplication: " + (Integer.parseInt(num1) * Integer.parseInt(num2)));
                        break;
                    case 4:
                        System.out.println("Division " + (Integer.parseInt(num1) / Integer.parseInt(num2)));
                        break;
                    default:
                        flag = false;
                        break;
                }
            }
        } catch (InvalidNumeralException exception) {
            System.out.println(exception.toString());
        }
    }
}
