package Java.basics;

public class Factorial {
    // binomial coefficient
    public static double binomialCoefficient(int n, int r) {
        return factorial(n)/(factorial(r)*factorial(n-r));
    }

    // factorial of number
    public static int factorial(int num) {
        int result = 1;
        for (int i=num; i>0; i--) {
            result *= i;
        }
        
        return result;
    }

    public static void main(String[] args) {
        System.out.println(factorial(5));
        System.out.println(binomialCoefficient(5, 2));
    }
}
