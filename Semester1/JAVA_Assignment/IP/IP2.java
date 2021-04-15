import java.sql.*;
import java.util.*;

class IP2 {
    static Connection con;
    static Statement statement;
    static Scanner scan;

    public static void main(String[] a) {
        connectDBMS();
        scan = new Scanner(System.in);
        boolean flag = true;
        while (flag) {
            System.out.print("""
                    Select
                    1. Add record
                    2. Search Record
                    3. Modify record
                    4. Print all records
                    5. Exit:\s""");
            int inp = scan.nextInt();
            switch (inp) {
                case 1:
                    insertInTo();
                    break;
                case 2:
                    searchRecord();
                    break;
                case 3:
                    modifyRecord();
                    break;
                case 4:
                    showRecord();
                    break;
                default:
                    flag = false;
                    break;
            }
        }
    }

    static void connectDBMS() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            System.out.println(" Unable to load driver. ");
        }
        String url = "xxx";
        String username = "xxx";
        String password = "xxx";
        try {
            con = DriverManager.getConnection(url, username, password);
            System.out.println("Connection Established. ");
            statement = con.createStatement();
            String sql = """
                    CREATE TABLE STUDENT(
                        RollNo int PRIMARY KEY,
                        SName char(16),
                        City char(16), 
                        Age int,
                        Gender char(6)
                    );
                    """;
            statement.executeUpdate(sql);
        } catch (SQLException e) {
            System.out.println(" Error connecting to database:  " + e);
        }
    }

    static void insertInTo() {
        System.out.print("Enter RollNo: ");
        int RollNum = scan.nextInt();
        scan.nextLine();

        System.out.print("Enter Name: ");
        String Name = scan.nextLine();

        System.out.print("Enter City: ");
        String City = scan.nextLine();

        System.out.print("Enter Age: ");
        int Age = scan.nextInt();
        scan.nextLine();

        System.out.print("Enter Gender: ");
        String Gender = scan.nextLine();

        String sql = "INSERT INTO STUDENT VALUES("
                + RollNum + ",'"
                + Name + "','"
                + City + "',"
                + Age + ",'"
                + Gender + "');";
        System.out.println(sql);
        try {
            statement.executeUpdate(sql);
            System.out.println("Record Inserted");
        } catch (SQLException e) {
            System.out.println(" Error connecting to database:  " + e);
        }
    }

    static void searchRecord() {
        System.out.print("Enter RollNo to search: ");
        int RollNum = scan.nextInt();
        try {
            String sql = "Select * from STUDENT where RollNo="
                    + RollNum + ";";
            ResultSet rs = statement.executeQuery(sql);
            while (rs.next()) {
                for (int i = 1; i <= 5; i++) {
                    if (i > 1) System.out.print(",  ");
                    String columnValue = rs.getString(i);
                    System.out.print(columnValue);
                }
                System.out.println("\n");
            }
        } catch (SQLException e) {
            System.out.println(" Error connecting to database:  " + e);
        }
    }

    static void modifyRecord() {
        System.out.print("Enter RollNo: ");
        int RollNum = scan.nextInt();
        scan.nextLine();

        System.out.print("Enter new name: ");
        String Name = scan.nextLine();

        String sql = "Update STUDENT SET SName='"
                + Name + "' where RollNo=" + RollNum;
        try {
            statement.executeUpdate(sql);
            System.out.println("Record Updated");
        } catch (SQLException e) {
            System.out.println(" Error connecting to database:  " + e);
        }
    }

    static void showRecord() {
        String sql = "Select * from STUDENT;";
        System.out.println("\nData: ");
        try {
            ResultSet rs = statement.executeQuery(sql);
            while (rs.next()) {
                for (int i = 1; i <= 5; i++) {
                    if (i > 1) System.out.print(",  ");
                    String columnValue = rs.getString(i);
                    System.out.print(columnValue);
                }
                System.out.println("\n");
            }
        } catch (SQLException e) {
            System.out.println(" Error connecting to database:  " + e);
        }
    }
}

