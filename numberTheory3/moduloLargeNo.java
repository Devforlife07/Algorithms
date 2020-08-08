import java.util.*;

public class moduloLargeNo {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        int b = sc.nextInt();
        int mod = sc.nextInt();
        sc.close();
        getResult(a, b, mod);
    }

    public static void getResult(String a, int b, int mod) {
        int ans = 0;
        for (int i = 0; i < a.length(); i++) {
            ans *= 10;
            char cc = a.charAt(i);
            ans = (ans % mod + Character.getNumericValue(cc)) % mod;

        }
        int res = ans;
        for (int i = 1; i <= b - 1; i++) {
            res = ((res % mod) * (ans % mod)) % mod;
        }
        System.out.println(res);
    }
}