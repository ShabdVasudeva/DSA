package Java.basics;

public class Loops {
    public static void main(String[] args) {
        for(int i=0; i<10; i++) {
            System.out.println("i = " + i);
        }
        int n = 20;
        while (n >= 11) {
            System.out.println("n = " + n--);
        }
        int j = 40;
        do {
            System.out.println("j = " + j--);
        } while (j > 30);
    }
}
