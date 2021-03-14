import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

public class EP1 {
    static TreeSet<Result> resultTreeSet = new TreeSet<>(new CompareResults());
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number of student: ");
        int numStudent = scan.nextInt();
        scan.nextLine();

        for (int i = 0; i < numStudent; i++) {
            System.out.print("Enter RollNo SemNo Marks_Of_Five_Subject(Separated by space): ");
            String[] inp = (scan.nextLine()).split(" ");
            int[] marks = {
                    Integer.parseInt(inp[2]),
                    Integer.parseInt(inp[3]),
                    Integer.parseInt(inp[4]),
                    Integer.parseInt(inp[5]),
                    Integer.parseInt(inp[6]),
            };
            Result result = new Result(
                    inp[0],
                    inp[1],
                    marks,
                    Arrays.stream(marks).sum()
            );
            resultTreeSet.add(result);
        }

        for (Result res : resultTreeSet) {
            System.out.println("RollNo: " + res.getRollNo());
            System.out.print("Sem" + res.getSemester() + " ");
            for (int i : res.getScore()) {
                System.out.print(i + " ");
            }
            System.out.print(res.getSum() + "\n");
            System.out.println("Average: " + (res.getSum() / 5));
        }
    }
}

class Result {
    String RollNo, Semester;
    int[] score;
    int sum;

    public Result(String rollNo, String semester, int[] score, int sum) {
        RollNo = rollNo;
        Semester = semester;
        this.score = score;
        this.sum = sum;
    }

    public String getRollNo() {
        return RollNo;
    }

    public String getSemester() {
        return Semester;
    }

    public int[] getScore() {
        return score;
    }

    public int getSum() {
        return sum;
    }
}

class CompareResults implements Comparator<Result> {
    @Override
    public int compare(Result ob1, Result ob2) {
        if (Integer.parseInt(ob1.getSemester()) > Integer.parseInt(ob2.getSemester())) {
            return 1;
        } else if (Integer.parseInt(ob1.getSemester()) < Integer.parseInt(ob2.getSemester())) {
            return -1;
        } else {
            if (Integer.parseInt(ob1.getRollNo()) > Integer.parseInt(ob2.getRollNo())) {
                return 1;
            } else if (Integer.parseInt(ob1.getRollNo()) < Integer.parseInt(ob2.getRollNo())) {
                return -1;
            } else return 0;
        }
    }
}
