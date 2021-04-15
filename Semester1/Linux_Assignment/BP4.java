package com.company;

import java.io.*;
import java.util.Scanner;

public class BP4 {
    static boolean wrt = false, mutex = false;
    static int readCount = 0;
    static int value = 0;

    public static void main(String[] args) {
        FiReader[] reader = new FiReader[10];
        FiWriter[] writer = new FiWriter[10];
        for (int i = 0; i < 10; i++) {
            reader[i] = new FiReader();
            writer[i] = new FiWriter();
        }
        for (int i = 0; i < 10; i++) {
            reader[i].start();
            writer[i].start();
        }
    }

    static class FiWriter extends Thread {
        @Override
        public void run() {
//
//            // Waiting for previous writer
//            while (wrt) {
//                System.out.print("");
//            }
//
//            // Locking Writer and Reader
//            wrt = true;
//            mutex = true;

            // Critical section
            BufferedWriter out = null;
            try {
                out = new BufferedWriter(new FileWriter("shared.txt", false));
                value = value + 1;
                System.out.println("Writing: " + (value));
                out.write(String.valueOf(value));
                out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
//
//            // Leaving Critical section
//            wrt = false;
//            mutex = false;
        }
    }

    static class FiReader extends Thread {
        @Override
        public void run() {
//
//            // Waiting for other reader to unlock mutex
//            while (mutex) {
//                System.out.print("");
//            }
//            mutex = true;
//            readCount++;
//            if (readCount == 1) {
//                wrt = true; // Locking writer when reader is active
//            }
//            mutex = false;

            // Critical Section
            try {
                File myObj = new File("shared.txt");
                Scanner myReader = new Scanner(myObj);
                String data = myReader.nextLine();
                System.out.println("Reading: " + data);
                myReader.close();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

//            // Leave Critical section
//            while (mutex) {
//                System.out.print("");
//            }
//            mutex = true;
//            readCount--;
//            if (readCount == 0) {
//                wrt = false; // Unlocking writer if all reading process is done.
//            }
//            mutex = false;
        }
    }
}
