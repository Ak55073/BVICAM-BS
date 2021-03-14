import java.io.*;
import java.util.Scanner;

public class GP1 {
    public static void main(String[] args) {
        // usingFile();
        usingBuffer();
    }

    static void usingFile() {
        try {
            FileWriter myWriter = new FileWriter("compiled.txt");
            File myObj = new File("sample.txt");
            Scanner myReader = new Scanner(myObj);
            System.out.println("Content of file:");
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                int[] count = calcString(data);
                String temp = data + "(vowels-" + count[0] + ", consonants-" + count[1] + ", spaces-" + count[2] + ")";
                myWriter.write(temp + "\n");
                System.out.println(temp);
            }
            myReader.close();
            myWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void usingBuffer() {
        try {
            File readingFile = new File("sample.txt");
            FileReader fileReader = new FileReader(readingFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            File writingFile = new File("compiled.txt");
            FileWriter fileWriter = new FileWriter(writingFile);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            String line;
            while ((line = bufferedReader.readLine()) != null) {
                int[] count = calcString(line);
                String temp = line + "(vowels-" + count[0] + ", consonants-" + count[1] + ", spaces-" + count[2] + ")";
                bufferedWriter.write(temp + "\n");
                System.out.println(temp);
            }
            bufferedReader.close();
            bufferedWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static int[] calcString(String text) {
        int spaces = 0, vowels = 0, letters = 0;
        text = text.toLowerCase();
        for (int i = 0; i < text.length(); i++) {

            char a = text.charAt(i);
            if (a == ' ') {
                spaces++;
            } else if ("aeiou".indexOf(a) >= 0) {
                vowels++;
            }

            if ((int) a >= 97 && (int) a <= 122) {
                letters++;
            }
        }
        return new int[]{vowels, letters, spaces};
    }
}
