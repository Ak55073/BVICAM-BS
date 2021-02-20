import java.util.Arrays;
import java.util.Scanner;

public class CP4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter Number of student: ");
        int numStudent = scan.nextInt();
        scan.nextLine();

        int[][] grades = new int[numStudent][5];
        double[] avg = new double[numStudent];
        for(int i=0;i<numStudent;i++){
            System.out.print("Enter marks of student(separated by space: ");
            String marks = scan.nextLine();
            int ind=0;
            double mark = 0.00;
            for(String ch:marks.split(" ")){
                grades[i][ind] = Integer.parseInt(ch);
                mark += grades[i][ind++];
            }
            avg[i] = (mark/5.00);
        }

        for(int i=0;i<numStudent;i++){
            System.out.println("Student marks: "+ Arrays.toString(grades[i])+" Average: "+avg[i]);
        }

        int classHighest=0,classLowest=101;
        for(int i=0;i<numStudent;i++){
            if (avg[i] > classHighest){
                classHighest = (int) avg[i];
            }
            if (avg[i] < classLowest){
                classLowest = (int) avg[i];
            }
        }

        System.out.println("Class highest: "+classHighest);
        System.out.println("Class lowest: "+classLowest);
    }
}
