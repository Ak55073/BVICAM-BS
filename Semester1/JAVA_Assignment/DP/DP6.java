import java.io.*;
import java.util.Scanner;

public class DP6 {
    public static void main(String[] args) {
        switch (Integer.parseInt(args[0])) {
            case 1:
                shredFile(args[1]);
                break;
            case 2:
                combineFile(args[1], args[2], args[3], args[4]);
                break;
        }
    }

    static void shredFile(String fileName) {
        File fileObj = new File(fileName);
        if (fileObj.delete()) {
            System.out.println("Shredding file: " + fileObj.getName());
            System.out.println("File deleted.");
        } else {
            System.out.println("File not found.");
        }
    }

    static void combineFile(String fileNameA, String fileNameB, String fileNameC, String fileNameDest) {
        FileWriter myWriter = null;
        try {
            myWriter = new FileWriter(fileNameDest);
        } catch (IOException e) {
            e.printStackTrace();
        }

        String[] fileNames = {fileNameA, fileNameB, fileNameC};
        for (String fileName : fileNames) {
            try {
                File myObj = new File(fileName);
                Scanner myReader = new Scanner(myObj);
                while (myReader.hasNextLine()) {
                    String data = myReader.nextLine();
                    myWriter.write(data + "\n");
                    System.out.println("Content of file" + fileName + ": " + data);
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("File not found.");
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        try {
            if (myWriter != null) {
                myWriter.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("File copying completed");
    }
}
