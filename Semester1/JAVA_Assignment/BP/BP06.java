import java.util.Scanner;

class BP06{
	static int teamID[][];
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter number of team: ");
		int teamLimit = scan.nextInt();
		scan.nextLine();
		System.out.print("Enter number of player(each team): ");
		int playerLimit = scan.nextInt();
		scan.nextLine();
		
		int dataID[][] = new int[teamLimit][playerLimit+1];
		for(int i=0;i<teamLimit;i++){
			System.out.print("\nEnter team id: ");
			dataID[i][0] = scan.nextInt();
			scan.nextLine();
			for(int j=1;j<playerLimit+1;j++){
				System.out.print("Enter player id: ");
				dataID[i][j] = scan.nextInt();
				scan.nextLine();
			}
		}
		
		System.out.print("\nEnter teamID to search: ");
		int srchID = scan.nextInt();
		scan.nextLine();
		for(int i=0;i<teamLimit;i++){
			if (dataID[i][0]==srchID){
				System.out.print("\nPlayer in the team: ");
				for(int j=1;j<playerLimit+1;j++){
					System.out.print(dataID[i][j]+" ");
				}
			}
		}
		
	}
}