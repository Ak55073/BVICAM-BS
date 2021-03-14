import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class GP4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter string to search: ");
        String token = scan.nextLine();
        int count = 0;
        try {
            RandomAccessFile file = new RandomAccessFile("gp4.txt", "r");
            file.seek(0);
            long current = 0;
            while (current < file.length()) {
                String result = file.readLine();
                for (String word : result.split(" ")) {
                    if (word.equals(token)) {
                        count++;
                    }
                }
                current = file.getFilePointer();
            }
            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Total occurrence of " + token + ": " + count);

    }
}