import java.util.Scanner;

class AP8{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		
		System.out.print("Enter hours worked: ");
		double hour = scan.nextDouble();
		if (hour > 60 || hour <= 0){
			System.out.print("Working hour must be between 1hour to 60hours");
			return;
		}
		
		System.out.print("Enter Base pay: ");
		double pay = scan.nextDouble();
		if (pay < 8.0){
			System.out.print("Base pay must not be less than the minimum wage ($8.00 an hour).");
			return;
		}
		double totalPay = 1;
		if (hour > 40){
			totalPay = 40 * pay;
			totalPay = totalPay + ((pay*1.5)*(hour-40));
		} else{
			totalPay = hour * pay;
		}
		
		System.out.print("Your total pay generated: "+totalPay);
	}
}
