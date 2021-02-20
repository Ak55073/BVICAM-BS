public class DP3 {
    public static void main(String[] args) throws InterruptedException {
        HelloWorld[] helloWorld = new HelloWorld[50];
        for(int i=0;i<50;i++){
            helloWorld[i] = new HelloWorld(50-i);
        }
        for(int i=0;i<50;i++){
            helloWorld[i].start();
            helloWorld[i].join();
        }
    }
}

class HelloWorld extends Thread{
    int num;
    HelloWorld(int num){
        this.num = num;
    }
    @Override
    public synchronized void run() {
        System.out.println("Hello world from Thread"+num);
    }
}
