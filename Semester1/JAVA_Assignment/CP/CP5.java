public class CP5 {
    public static void main(String[] args) {
        Electronic electronic = new Electronic();
        Electronic.Phone ph1=  electronic.new Phone(1000);
        Electronic.TV tv1 = new Electronic.TV(700);
        System.out.println("Cost of TV: "+tv1.cost());
        System.out.println("Cost of Phone: "+ph1.cost());
    }
}

class Electronic{
    static class TV{
        int cost;
        TV(int cost){
            this.cost = cost;
        }
        int cost(){
            return cost;
        }
    }

    class Phone{
        int cost;
        Phone(int cost){
            this.cost = cost;
        }
        int cost(){
            return cost;
        }
    }
}
