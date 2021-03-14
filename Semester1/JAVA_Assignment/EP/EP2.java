import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class EP2 {
    static TreeSet<Employee> employeeTreeSet;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd-MM-yyyy");
        System.out.print("Enter number of employee: ");
        int numEmployee = scan.nextInt();
        scan.nextLine();

        System.out.print("Sort using:\n1.ID\n2.Name\n3.Salary\n4.Age\n5.Date of Join: ");
        int sortMethod = scan.nextInt();
        scan.nextLine();
        switch (sortMethod) {
            case 1:
                employeeTreeSet = new TreeSet<>(new CompareEmployeeID());
                break;
            case 2:
                employeeTreeSet = new TreeSet<>(new CompareEmployeeName());
                break;
            case 3:
                employeeTreeSet = new TreeSet<>(new CompareEmployeeSalary());
                break;
            case 4:
                employeeTreeSet = new TreeSet<>(new CompareEmployeeAge());
                break;
            default:
                employeeTreeSet = new TreeSet<>(new CompareEmployeeDoJ());
        }

        for (int i = 0; i < numEmployee; i++) {
            System.out.print("Enter employee ID NAME AGE SALARY JoiningDate(dd-MM-yyyy): ");
            String[] inp = (scan.nextLine()).split(" ");
            try {
                Employee employee = new Employee(
                        Integer.parseInt(inp[0]),
                        inp[1],
                        Integer.parseInt(inp[2]),
                        Integer.parseInt(inp[3]),
                        simpleDateFormat.parse(inp[4])
                );
                employeeTreeSet.add(employee);
            } catch (ParseException e) {
                e.printStackTrace();
            }
        }

        for (Employee emp : employeeTreeSet) {
            System.out.println("Employee (" + emp.getID() + ") " + emp.getName() + ":");
            System.out.println("Date Of Joining:  " + simpleDateFormat.format(emp.getDateOfJoining()) + " | " + "Age: " + emp.getAge() + " | " + "Salary " + emp.getSalary() + "."
            );
        }

    }
}

class Employee {
    int ID, Salary, Age;
    String Name;
    Date DateOfJoining;

    public Employee(int ID, String name, int age, int salary, Date dataOfJoining) {
        this.ID = ID;
        Salary = salary;
        Age = age;
        Name = name;
        DateOfJoining = dataOfJoining;
    }

    public int getID() {
        return ID;
    }

    public int getSalary() {
        return Salary;
    }

    public int getAge() {
        return Age;
    }

    public String getName() {
        return Name;
    }

    public Date getDateOfJoining() {
        return DateOfJoining;
    }
}

class CompareEmployeeID implements Comparator<Employee> {
    @Override
    public int compare(Employee ob1, Employee ob2) {
        if (ob1.getID() < ob2.getID()) {
            return 1;
        } else if (ob1.getID() > ob2.getID()) {
            return -1;
        } else return 0;
    }
}

class CompareEmployeeName implements Comparator<Employee> {
    @Override
    public int compare(Employee ob1, Employee ob2) {
        return ob1.getName().compareTo(ob2.getName());
    }
}

class CompareEmployeeSalary implements Comparator<Employee> {
    @Override
    public int compare(Employee ob1, Employee ob2) {
        if (ob1.getSalary() > ob2.getSalary()) {
            return 1;
        } else if (ob1.getSalary() < ob2.getSalary()) {
            return -1;
        } else return 0;
    }
}

class CompareEmployeeAge implements Comparator<Employee> {
    @Override
    public int compare(Employee ob1, Employee ob2) {
        if (ob1.getAge() > ob2.getAge()) {
            return 1;
        } else if (ob1.getAge() < ob2.getAge()) {
            return -1;
        } else return 0;
    }
}

class CompareEmployeeDoJ implements Comparator<Employee> {
    @Override
    public int compare(Employee ob1, Employee ob2) {
        if (ob1.getDateOfJoining().before(ob2.getDateOfJoining())) {
            return -1;
        } else if (ob1.getDateOfJoining().after(ob2.getDateOfJoining())) {
            return 1;
        } else return 0;
    }
}