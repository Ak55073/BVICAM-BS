import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

class Employee {
    int employeeID;
    String employeeName, EmployeeDepartment;

    public Employee(int employeeID, String employeeName, String employeeDepartment) {
        this.employeeID = employeeID;
        this.employeeName = employeeName;
        EmployeeDepartment = employeeDepartment;
    }

    public int getEmployeeID() {
        return employeeID;
    }

    public String getEmployeeName() {
        return employeeName;
    }

    public String getEmployeeDepartment() {
        return EmployeeDepartment;
    }
}

public class DP8Server {
    public static void main(String[] args) throws IOException {
        Employee[] employeesData = new Employee[3];
        employeesData[0] = new Employee(1, "Abhinav", "CSI");
        employeesData[1] = new Employee(2, "Vid", "IT");
        employeesData[2] = new Employee(3, "Jay", "Teaching");

        ServerSocket serverSocket = new ServerSocket(888);

        Socket socket = serverSocket.accept();
        System.out.println("Connection established");

        PrintStream printStream = new PrintStream(socket.getOutputStream());

        BufferedReader clientInput = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        BufferedReader keyboardInput = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String clientString;
            while ((clientString = clientInput.readLine()) != null) {
                for (Employee employee : employeesData) {
                    if (String.valueOf(employee.getEmployeeID()).equals(clientString)) {
                        printStream.println(
                                "Employee ID: " + employee.getEmployeeID() +
                                        " | Employee Name: " + employee.getEmployeeName() +
                                        " | Employee Department: " + employee.getEmployeeDepartment()
                        );
                    }
                }
            }
            System.out.println("Connection closed!");
            clientInput.close();
            printStream.close();
            keyboardInput.close();
            serverSocket.close();
            socket.close();
            break;
        }
    }
}