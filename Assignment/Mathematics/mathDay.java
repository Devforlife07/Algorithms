import java.io.*;
import java.util.*;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static int p;

    public static long fastExponentiaitio(long base, int power) {
        if (base == 0)
            return 0l;
        if (power == 0)
            return 1;
        long temp = power;
        long res = 1l;
        while (temp > 0) {
            if ((temp & 1) == 1) {
                res = ((res % p) * (base % p)) % p;
            }
            temp >>= 1;
            base = ((base % p) * (base % p)) % p;
        }
        return res;
    }

    public static void getRes(int a, int n, int p) {
        // a = a % p;
        long res = a;
        for (int i = 2; i <= n; i++) {
            res = ((res % p) * (fastExponentiaitio(res, i) % p)) % p;
        }
        System.out.println(res);
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            int n = sc.nextInt();
            p = sc.nextInt();
            getRes(a, n, p);
        }
    }
}