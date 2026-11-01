package Java.basics;

public class Even {
    public static void checkEven(int num) {
        if (num % 2 == 0) {
            System.out.println("num = " + num + " is an even number");
        } else {
            System.err.println("num = " + num + " is an odd number");
        }
    }
    public static void main(String[] args) {
        checkEven(6);
        checkEven(9);
    }
}
