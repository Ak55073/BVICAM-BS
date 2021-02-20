import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DP7 {
    public static void main(String[] args) {
        switch (args[0]) {
            case "-cc":
                System.out.println("Number of characters in file: " + countCharacters(args[1]));
                break;
            case "-cw":
                System.out.println("Number of lines in file: " + countWords(args[1]));
                break;
            case "-cl":
                System.out.println("Number of lines in file: " + countLines(args[1]));
                break;
            case "-s":
                System.out.println("Lines with word(" + args[2] + ") :" + searchWords(args[1], args[2]));
                break;
            default:
                System.out.println("Invalid flag.");
        }
    }

    static int countCharacters(String fileName) {
        int characterCount=0;
        try {
            File file = new File(fileName);
            Scanner myReader = new Scanner(file);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                for(int i=0;i<data.length();i++){
                    if(data.charAt(i) != ' '){
                        characterCount++;
                    }
                }
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
            e.printStackTrace();
        }
        return characterCount;
    }

    static int countWords(String fileName) {
        int wordCount=0;
        try {
            File file = new File(fileName);
            Scanner myReader = new Scanner(file);
            while (myReader.hasNextLine()) {
                String[] data = myReader.nextLine().split(" ");
                wordCount += data.length;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
            e.printStackTrace();
        }
        return wordCount;
    }

    static int countLines(String fileName) {
        int linewordCount=0;
        try {
            File file = new File(fileName);
            Scanner myReader = new Scanner(file);
            while (myReader.hasNextLine()) {
                myReader.nextLine();
                linewordCount++;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
            e.printStackTrace();
        }
        return linewordCount;
    }

    static String searchWords(String fileName, String words) {
        StringBuilder lineText= new StringBuilder();
        try {
            File file = new File(fileName);
            Scanner myReader = new Scanner(file);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                if (data.contains(words)){
                    lineText.append("\n").append(data);
                }
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
            e.printStackTrace();
        }
        return lineText.toString();
    }
}
