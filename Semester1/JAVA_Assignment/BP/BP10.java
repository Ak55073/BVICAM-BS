import java.util.Scanner;

interface Account {
    void openAccount(int balance);

    void closeAccount();

    void withdrawCash(int amount);

    void depositCash(int amount);

    void transferCash(CurrentAccount receiver, int amount);
    void transferCash(SavingAccount receiver, int amount);
}

class SavingAccount implements Account {
    int withdrawLimit = 6;
    int balance = 0;

    @Override
    public void openAccount(int balance) {
        if (balance<500){
            System.out.println("Minimum balance for saving account is Rs500");
            return;
        }
        this.balance = balance;
        System.out.println("BP.Account successfully opened!");
    }

    @Override
    public void closeAccount() {
        this.balance = 0;
        System.out.println("BP.Account successfully closed!");
    }

    @Override
    public void withdrawCash(int amount) {
        int newBalance = balance - amount;
        if (newBalance<500){
            System.out.println("Minimum balance for saving account is Rs500. Amount cannot be withdrawn.");
            return;
        }
        if (withdrawLimit == 0){
            System.out.println("Saving account withdraw limit reached.");
        } else{
            withdrawLimit--;
            System.out.println("You can withdraw "+withdrawLimit+" more time.");
        }
        balance = newBalance;
        System.out.println("Rs" + amount + " withdrawn. Remaining Balance: Rs" + balance);
    }

    @Override
    public void depositCash(int amount) {
        balance = balance + amount;
        System.out.println("Rs" + amount + " deposited. Current Balance: Rs" + balance);
    }

    @Override
    public void transferCash(SavingAccount receiver, int amount) {

    }

    @Override
    public void transferCash(CurrentAccount receiver, int amount) {
        int newBalance = this.balance - amount;
        if (newBalance<500){
            System.out.println("Minimum balance for saving account is Rs500. Amount cannot be transferred.");
            return;
        }
        if (withdrawLimit == 0){
            System.out.println("Saving account transfer limit reached.");
        } else{
            withdrawLimit--;
            System.out.println("You can transfer "+withdrawLimit+" more time.");
        }

        this.balance = newBalance;
        receiver.balance += amount;
        System.out.println("Rs" + amount + " transferred.");
    }

    public void currentBalance() {
        System.out.println("Current account balance: Rs"+this.balance);
    }
}

class CurrentAccount implements Account {
    int balance = 0;

    @Override
    public void openAccount(int balance) {
        if (balance<2000){
            System.out.println("Minimum balance for current account is Rs2000");
            return;
        }
        this.balance = balance;
        System.out.println("BP.Account successfully opened!");
    }

    @Override
    public void closeAccount() {
        this.balance = 0;
        System.out.println("BP.Account successfully closed!");
    }

    @Override
    public void withdrawCash(int amount) {
        int newBalance = balance - amount;
        if (newBalance<2000){
            System.out.println("Minimum balance for current account is Rs2000. Amount cannot be withdrawn.");
            return;
        }
        balance = newBalance;
        System.out.println("Rs" + amount + " withdrawn. Remaining Balance: Rs" + balance);
    }

    @Override
    public void depositCash(int amount) {
        balance = balance + amount;
        System.out.println("Rs" + amount + " deposited. Current Balance: Rs" + balance);
    }

    @Override
    public void transferCash(SavingAccount  receiver, int amount) {
        int newBalance = this.balance - amount;
        if (newBalance<2000){
            System.out.println("Minimum balance for current account is Rs2000. Amount cannot be transferred.");
            return;
        }

        this.balance -= newBalance;
        receiver.balance += amount;
        System.out.println("Rs" + amount + " transferred.");
    }

    @Override
    public void transferCash(CurrentAccount receiver, int amount) {

    }

    public void currentBalance() {
        System.out.println("Current account balance: Rs"+this.balance);
    }
}

public class BP10{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        SavingAccount ob1 = new SavingAccount();
        CurrentAccount ob2 = new CurrentAccount();

        boolean flag = true;
        while (flag) {
            System.out.print("\nEnter:\n1.Open new BP.Account\n2.Close BP.Account" +
                    "\n3.Withdraw Cash\n4.Deposit Cash\n5.Transfer Balance\n6.Check Balance\n7.Exit: ");
            int inp = scan.nextInt();
            scan.nextLine();
            int acc = 0;
            if (inp!=7) {
                System.out.print("\nSelect BP.Account:\n1.Saving BP.Account\n2.Current BP.Account: ");
                acc = scan.nextInt();
                scan.nextLine();
            }
            int amount;
            switch (inp) {
                case (1):
                    System.out.print("Enter initial balance: ");
                    amount = scan.nextInt();
                    scan.nextLine();
                    if (acc==1){
                        ob1.openAccount(amount);
                    } else{
                        ob2.openAccount(amount);
                    }
                    break;
                case (2):
                    if (acc==1){
                        ob1.closeAccount();
                    } else{
                        ob2.closeAccount();
                    }
                    break;
                case (3):
                    System.out.print("\nEnter amount to withdraw: ");
                    amount = scan.nextInt();
                    scan.nextLine();
                    if (acc==1){
                        ob1.withdrawCash(amount);
                    } else{
                        ob2.withdrawCash(amount);
                    }
                    break;
                case (4):
                    System.out.print("\nEnter amount to deposit: ");
                    amount = scan.nextInt();
                    scan.nextLine();
                    if (acc==1){
                        ob1.depositCash(amount);
                    } else{
                        ob2.depositCash(amount);
                    }
                    break;
                case (5):
                    System.out.print("\nEnter amount to transfer: ");
                    amount = scan.nextInt();
                    scan.nextLine();
                    if (acc==1){
                        ob1.transferCash(ob2, amount);
                    } else{
                        ob2.transferCash(ob1, amount);
                    }
                    break;
                case (6):
                    if (acc==1){
                        ob1.currentBalance();
                    } else{
                        ob2.currentBalance();
                    }
                    break;
                case (7):
                    flag = false;
                    break;
            }
        }
    }
}