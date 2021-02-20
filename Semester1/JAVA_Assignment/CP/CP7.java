import java.util.Scanner;

public class CP7 {
    static Scanner scan = new Scanner(System.in);
    static int xi, vi = 0;

    public static void main(String[] args) {
        try {
            switchDriven();
        } catch (NumberFormatException exception){
            System.out.println(exception.toString());
        }
    }

    static void switchDriven() {
        boolean flag = true;
        while (flag) {
            System.out.print("\nEnter\n1.Set initial position\n2.Set initial velocity(Default=0)\n3.Calculate position\n4.Exit: ");
            int inp = scan.nextInt();
            switch (inp) {
                case 1:
                    System.out.print("Enter initial position: ");
                    xi = scan.nextInt();
                    break;
                case 2:
                    System.out.print("Enter initial velocity: ");
                    vi = scan.nextInt();
                    break;
                case 3:
                    if (xi == 0) {
                        throw new NumberFormatException();
                    }
                    System.out.println(calcPosition());
                    break;
                default:
                    flag = false;
                    break;
            }
        }
    }

    static double calcPosition() {
        return (0.5 * (-9.81 * (10 * 10)) + (vi * 10) + xi);
    }
}
