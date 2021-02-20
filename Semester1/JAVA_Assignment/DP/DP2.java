import java.util.Scanner;

import static java.lang.Thread.sleep;

class CurrentAccount{
    int balance = 0;
    
    public void openAccount(int balance) {
        if (balance<2000){
            System.out.println("Minimum balance for current account is Rs2000");
            return;
        }
        this.balance = balance;
        System.out.println("Account successfully opened!");
    }
    
    public void closeAccount() {
        this.balance = 0;
        System.out.println("Account successfully closed!");
    }
    
    public void withdrawCash(int amount) {
        System.out.println("Withdrawing cash..........");
        class WithdrawCash implements Runnable{
            final int amount;
            WithdrawCash(int amount){
                this.amount = amount;
            }
            @Override
            public void run() {
                try {
                    sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                int newBalance = balance - amount;
                if (newBalance<2000){
                    System.out.println("Minimum balance for current account is Rs2000. Amount cannot be withdrawn.");
                    return;
                }
                balance = newBalance;
                System.out.println("Rs" + amount + " withdrawn. Remaining Balance: Rs" + balance);
            }
        }
        WithdrawCash withdrawCash = new WithdrawCash(amount);
        withdrawCash.run();
    }
    
    public void depositCash(int amount) {
        System.out.println("Depositing cash..........");
        class DepositCash implements Runnable{
            final int amount;
            DepositCash(int amount){
                this.amount = amount;
            }
            @Override
            public void run() {
                try {
                    sleep(5000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                balance = balance + amount;
                System.out.println("Rs" + amount + " deposited. Current Balance: Rs" + balance);
            }
        }
        DepositCash withdrawCash = new DepositCash(amount);
        withdrawCash.run();

    }
    public void currentBalance() {
        System.out.println("Current account balance: Rs"+this.balance);
    }
}

public class DP2 {
    public static void main(String[] args) throws InterruptedException {
        Scanner scan = new Scanner(System.in);

        CurrentAccount ob1 = new CurrentAccount();

        boolean flag = true;
        while (flag) {
            System.out.print("\nEnter:\n1.Open new Account\n2.Close Account" +
                    "\n3.Withdraw Cash\n4.Deposit Cash\n5.Check Balance\n6.Exit: ");
            int inp = scan.nextInt();
            scan.nextLine();
            int amount;
            switch (inp) {
                case (1):
                    System.out.print("Enter initial balance: ");
                    amount = scan.nextInt();
                    scan.nextLine();
                    ob1.openAccount(amount);
                    break;
                case (2):
                    ob1.closeAccount();
                    break;
                case (3):
                    System.out.print("\nEnter amount to withdraw: ");
                    amount = scan.nextInt();
                    scan.nextLine();
                    ob1.withdrawCash(amount);
                    break;
                case (4):
                    System.out.print("\nEnter amount to deposit: ");
                    amount = scan.nextInt();
                    scan.nextLine();
                    ob1.depositCash(amount);
                    break;
                case (5):
                    ob1.currentBalance();
                    break;
                case (6):
                    flag = false;
                    break;
            }
        }
    }
}
