class HiddenClass {
    void display(){
        System.out.println("Inside Anonymous class");
    }
}

interface HiddenInterface{
    void display();
}

public class CP6 {
    public static void main(String[] args) {
        HiddenClass hiddenClass = new HiddenClass(){
            @Override
            void display() {
                super.display();
            }
        };
        hiddenClass.display();

        HiddenInterface hiddenInterface = new HiddenInterface() {
            @Override
            public void display() {
                System.out.println("Inside Anonymous interface");
            }
        };
        hiddenInterface.display();

    }
}
