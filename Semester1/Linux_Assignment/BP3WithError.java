package com.company;

import java.util.LinkedList;
import java.util.Random;



public class BP3WithError {
    static LinkedList<Integer> list = new LinkedList<>();
    static int capacity = 5;
    static Random rand = new Random();

    public static void main(String[] args) {
        ProducerDriverError producerDriverError = new ProducerDriverError();
        ConsumerDriverError consumerDriverError = new ConsumerDriverError();
        producerDriverError.start();
        consumerDriverError.start();
    }

    static class ProducerDriverError extends Thread{
        @Override
        public void run() {
            super.run();
            for(int i=0;i<10;i++) {
                int value = rand.nextInt(100);
                if (list.size() == capacity) {
                    Thread.currentThread().interrupt();
                    System.out.println("Producer Error: Buffer Full can't produce item.");
                    return;
                }
                System.out.println("Item Produced:" + value);
                list.add(value);
            }
        }
    }

    static class ConsumerDriverError extends Thread{
        @Override
        public void run() {

            if (list.size() == 0) {
                Thread.currentThread().interrupt();
                System.out.println("Consumer Error: Buffer is Empty.");
                return;
            }

            for(int i=0;i<10;i++) {
                System.out.println("Consumed: " + list.removeFirst());
            }
        }
    }
}
