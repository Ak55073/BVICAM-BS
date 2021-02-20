public class DP1 {
    public static void main(String[] args) {
        // using Thread
        ThreadPalindrome threadPalindrome = new ThreadPalindrome();
        threadPalindrome.start();

        // using Runnable
        RunnablePalindrome runnablePalindrome = new RunnablePalindrome();
        runnablePalindrome.run();
    }
}

class RunnablePalindrome implements Runnable {
    @Override
    public void run() {
        for (int i = 100; i <= 1000; i++) {
            String inp = String.valueOf(i);
            int size = inp.length() - 1;
            boolean flag = true;
            for (int j = 0; j < inp.length() / 2; j++) {
                if (inp.charAt(j) != inp.charAt(size - j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println(inp + " is a palindrome(from runnable).");
            }
        }
    }
}

class ThreadPalindrome extends Thread {
    @Override
    public void run() {
        super.run();
        for (int i = 100; i <= 1000; i++) {
            String inp = String.valueOf(i);
            int size = inp.length() - 1;
            boolean flag = true;
            for (int j = 0; j < inp.length() / 2; j++) {
                if (inp.charAt(j) != inp.charAt(size - j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println(inp + " is a palindrome(from thread).");
            }
        }
    }
}
