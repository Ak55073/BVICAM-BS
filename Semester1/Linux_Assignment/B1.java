package com.company;

public class B1 {
    static boolean[] flag = {false, false}; // { Process 1, Process 2 }
    static int turn;
    static int value = 0;

    public static void main(String[] args) {
        System.out.println("Initial Shared variable: " + value);
        Task1 task1 = new Task1();
        Task2 task2 = new Task2();
        task1.start();
        task2.start();
    }

    static class Task1 extends Thread {
        @Override
        public void run() {
            for (int i = 0; i < 10; i++) {

                // Locking shared resources
                flag[0] = true;
                turn = 1;
               while (flag[1] && turn == 1) {
                    System.out.print("");
                }

                // Executing Critical section
                value++;
                System.out.println("Process1 increasing the value to "+value);

                // Unlocking Shared resources
                flag[0] = false;
            }
        }
    }

    static class Task2 extends Thread {
        @Override
        public void run() {
            for (int i = 0; i < 10; i++) {

                // Locking shared resources
                flag[1] = true;
                turn = 0;
                while (flag[0] && turn == 0) {
                    System.out.print("");
                }

                // Executing Critical section
                value--;
                System.out.println("Process2 decreasing the value to " + value);

                // Unlocking Shared resources
                flag[1] = false;
            }
        }
    }
}
