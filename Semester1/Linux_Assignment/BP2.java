package com.company;

import java.util.Arrays;

public class BP2 {
    static BakeryAlgo[] threads = new BakeryAlgo[10];
    static boolean[] flag = new boolean[10];
    static int[] processID = new int[10];
    static int sharedSum;

    public static void main(String[] args) {
        sharedSum = 0;
        for (int i = 0; i < 10; i++) {
            threads[i] = new BakeryAlgo(i);
            flag[i] = false;
        }
        for (int i = 0; i < 10; i++) {
            threads[i].start();
        }
    }

    static class BakeryAlgo extends Thread {
        int PID;

        BakeryAlgo(int PID) {
            this.PID = PID;
        }

        void lock(int i) {
            flag[i] = true;
            processID[i] = Arrays.stream(processID).max().getAsInt() + 1;
            flag[i] = false;

            for (int process = 0; process < 10; process++) {
                while (flag[process]) {
                    System.out.print("");
                }
                while ((processID[process] != 0) && ((processID[process] < processID[i]) || (process < i))) {
                    System.out.print("");
                }
            }
        }

        void unlock(int i) {
            processID[i] = 0;
        }

        @Override
        public void run() {
            // Locking other processes
            //lock(PID);

            // Entering critical section
            System.out.println("Critical Section being using by P" + PID);
            for (int i = 0; i <= 100; i++) {
                sharedSum += i;
            }
            System.out.println("Sum from process" + PID + ":" + sharedSum);

            // Unlocking other processes
            //unlock(PID);
        }
    }
}

