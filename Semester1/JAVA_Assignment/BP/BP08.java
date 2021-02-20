import java.util.Scanner;

class BP08{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		
		double reportCard[][] = new double[10][7];
		
		double highAvg=0;
		int top=0;
		for(int i=0;i<10;i++){
			
			System.out.print("Enter student Roll no: ");
			reportCard[i][0] = scan.nextInt();
			scan.nextLine();
			
			double sum = 0;
			for(int j=1;j<6;j++){
				System.out.print("Enter marks: ");
				reportCard[i][j] = scan.nextInt();
				scan.nextLine();
				sum = sum + reportCard[i][j];
			}
			
			sum = (sum / 500.0)*100;
			reportCard[i][6] = sum;
			if (sum>highAvg){
				highAvg = sum;
				top = i;
			}
			
		}
		
		System.out.println("Student with rollno: "+reportCard[top][0]+" topped with average marks: "+highAvg);
		System.out.print("Marks: ");
		for(int j=1;j<6;j++){
			System.out.print(reportCard[top][j]+", ");
		}
	
	}
}