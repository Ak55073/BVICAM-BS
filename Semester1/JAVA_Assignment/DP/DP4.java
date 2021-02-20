public  class  DP4  {
    private static int  counter  =  0 ;

    public  static  void  main ( String []  args )  throws  InterruptedException  {
        IncrementerThread[] incrementerThreads = new IncrementerThread[10];
        for (int i = 0; i < 10; i++){
            incrementerThreads[i] = new IncrementerThread();
        }
        for (int i = 0; i < 10; i++){
            incrementerThreads[i].start();
            incrementerThreads[i].join(); // Will print 100 only when, all thread are joined.
        }
        System.out.println("Counter value: "+counter);
    }

    static class IncrementerThread extends Thread {
        public synchronized void run() {
            for (int i = 0; i < 10; i++) {
                counter++;
            }
        }
    }
}