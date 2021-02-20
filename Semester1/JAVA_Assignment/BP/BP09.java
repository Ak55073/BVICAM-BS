import java.util.Scanner;

class BP09{
	static int productID[][];
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter number of supplier: ");
		int supplyLimit = scan.nextInt();
		scan.nextLine();
		System.out.print("Enter number of product(each supplier): ");
		int productLimit = scan.nextInt();
		scan.nextLine();
		
		int dataID[][] = new int[supplyLimit][productLimit+1];
		for(int i=0;i<supplyLimit;i++){
			System.out.print("\nEnter supplier id: ");
			dataID[i][0] = scan.nextInt();
			scan.nextLine();
			for(int j=1;j<productLimit+1;j++){
				System.out.print("Enter product id: ");
				dataID[i][j] = scan.nextInt();
				scan.nextLine();
			}
		}
		
		int flag = 1;
		while(flag!=0){
			System.out.print("\nEnter:\n1.Search with supplier ID\n2.Search with product ID\n3.Exit: ");
			int inp = scan.nextInt();
			scan.nextLine();
			int srchID;
			switch(inp){
				case (1):
					System.out.print("\nEnter Supplier ID to search: ");
					srchID = scan.nextInt();
					scan.nextLine();
					for(int i=0;i<supplyLimit;i++){
						if (dataID[i][0]==srchID){
							System.out.print("Supplier provide: ");
							for(int j=1;j<productLimit+1;j++){
								System.out.print(dataID[i][j]+" ");
							}
							System.out.println();
						}
					}
					break;
				case (2):
					System.out.print("\nEnter Product ID to search: ");
					srchID = scan.nextInt();
					scan.nextLine();
					System.out.print("Product is supplied by: ");
					for(int i=0;i<supplyLimit;i++){
						for(int j=1;j<productLimit+1;j++){
							if (dataID[i][j]==srchID){
								System.out.print(dataID[i][0]+" ");
							}
						}
					}
					System.out.println();
					break;
				case (3):
					flag = 0;
					break;
			}
		}
	}
}