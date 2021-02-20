import java.time.DayOfWeek;
import java.time.LocalDate;
import java.util.Scanner;


public class CP10 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter year(yyyy): ");
        int year = scan.nextInt();
        scan.nextLine();

        System.out.print("Enter month(mm): ");
        int month = scan.nextInt();
        scan.nextLine();

        System.out.print("Enter day(dd): ");
        int day = scan.nextInt();
        scan.nextLine();

        CalendarAssistant calendarAssistant = new CalendarAssistant(year, month, day);
        System.out.println("Is Date valid? " + calendarAssistant.checkData());
        System.out.println("Leap Year: " + calendarAssistant.isLeapYear());
        System.out.println("Day of week: " + calendarAssistant.dayOfWeek());
        System.out.println("Date: " + calendarAssistant.toString());
    }
}

class CalendarAssistant {
    int day, month, year;
    final static String[] weekArray = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    final static String[] monthArray = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
    };

    CalendarAssistant(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    boolean checkData() {
        if (year < 1 || year > 9999) {
            System.out.println("Invalid year!");
            return false;
        }
        if (month < 1 || month > 12) {
            System.out.println("Invalid month!");
            return false;
        }
        return validDay();
    }

    boolean validDay() {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31)) {
            return false;
        } else if ((month == 2) && isLeapYear() && (day < 1 || day > 29)) {
            return false;
        } else if ((month == 2) && !isLeapYear() && (day < 1 || day > 28)) {
            return false;
        } else return (month != 4 && month != 6 && month != 9 && month != 11) || (day >= 1 && day <= 30);
    }

    boolean isLeapYear() {
        return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    }

    int dayOfWeek() {
        LocalDate localDate = LocalDate.of(year, month, day);
        DayOfWeek dayOfWeek = DayOfWeek.from(localDate);
        return dayOfWeek.getValue();

    }

    public String toString() {
        return (weekArray[dayOfWeek()] + " " + day + " " + monthArray[month - 1] + " " + year);
    }
}
