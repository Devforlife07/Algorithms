import java.util.*;

class birthdayParadox {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        double p = sc.nextDouble();
        double i = (double) 1;
        int c = 1;
        while ((i >= p)) {
            i = i * (((double) (365 - c) / 365));
            // System.out.println(i);
            c++;
        }
        System.out.println(c);
    }
}