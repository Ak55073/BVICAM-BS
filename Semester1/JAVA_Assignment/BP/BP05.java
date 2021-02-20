import java.util.Scanner;

class BP05{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter row: ");
		int len = scan.nextInt();
		
		int arr[][] = new int[len][];
		
		int cel = 1;
		for(int i=0;i<len;i++){
			arr[i] = new int[cel];
			int pos = 0;
			for(int j=1;j<=cel;j++){
				arr[i][pos++] = j;
			}
			cel += 1;
		}
		
	
		for(int num[]:arr){
			System.out.print(" ".repeat(len-1));
			for(int val:num){
				System.out.print(val);
			}
			System.out.println("");
		}

		int space = len - 1;
		for(int num[]:arr){
			System.out.print(" ".repeat(space));
			for(int j=(num.length-1);j>=0;j--){
				System.out.print(num[j]);
			}
			space--;
			System.out.println("");
		}
	}
}