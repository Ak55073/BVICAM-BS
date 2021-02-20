class CP1 {
    public static void main(String[] args) {
        int a = 50;
        System.out.println("Defining int: " + a);
        autoBoxing(a);

        Integer b = Integer.valueOf("500");
        System.out.println("Defining Integer: " + b);
        unBoxing(b);
    }

    static void autoBoxing(Integer a) {
        System.out.println("AutoBoxing int to Integer: "+a);
        int num = a;
        System.out.println("UnBoxing Integer to int: "+num);
    }

    static void unBoxing(int b) {
        System.out.println("UnBoxing Integer to int: "+b);
        Integer num = b;
        System.out.println("AutoBoxing int to Integer: "+num);
    }
}