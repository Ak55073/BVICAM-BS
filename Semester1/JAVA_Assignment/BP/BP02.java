import java.util.Scanner;

class BP2{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		
		System.out.print("Enter number of data: ");
		int dataCount = scan.nextInt();
		scan.nextLine();
		
		int minTime=-1;
		String minRunner = "";
		for(int i=0;i<dataCount;i++){
			System.out.print("Enter data: ");
			String temp[] = scan.nextLine().split(" ");
			if (minTime==-1 || Integer.parseInt(temp[1]) < minTime){
				minTime= Integer.parseInt(temp[1]);
				minRunner = temp[0];
			};
		}
			
		System.out.print("Fastest Runner is "+minRunner
		+" with Completion time of "+minTime+ " mins");
	}
} 