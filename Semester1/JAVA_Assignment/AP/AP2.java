import java.util.Scanner;

 class AP2{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		double values[] = new double[10];
		for (int i=0;i<10;i++){
			System.out.print("Enter "+(i+1)+" value= ");
			values[i] = scan.nextDouble();
		}
		System.out.println("AP.Sum of Reciprocator= "
		+((1.0/values[0]) + (1.0/values[1]) + (1.0/values[2]) + (1.0/values[3]) + (1.0/values[4]) + (1.0/values[5]) + (1.0/values[6]) + (1.0/values[7]) + (1.0/values[8]) + (1.0/values[9])));
	}
} 
