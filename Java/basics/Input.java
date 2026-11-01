package Java.basics;

import java.util.Scanner;

public class Input {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        float f = scanner.nextFloat();
        double d = scanner.nextDouble();
        String s = scanner.nextLine();
        
        scanner.close();
    }
}
