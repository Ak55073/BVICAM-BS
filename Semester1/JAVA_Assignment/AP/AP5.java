import java.util.Scanner;

class AP5{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		
		int val[] = new int[3];
		System.out.print("Enter 1st num: ");
		val[0] = scan.nextInt();
		System.out.print("Enter 2nd num: ");
		val[1] = scan.nextInt();
		System.out.print("Enter 3rd num: ");
		val[2] = scan.nextInt();
		
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if (i!=j && j!=k && i!=k){
						System.out.println("("+val[i]+","+val[j]+","+val[k]+")");
					}
				}
			}
		}
	}
}