import java.io.*;
import java.util.*;

public class bigGCD {
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

    public static int ans(int a, int b) {
        return b == 0 ? a : ans(b, a % b);
    }

    public static void getAns(int m, String n) {
        if (m == 0) {
            System.out.println(n);
            return;
        }
        int res = 0;
        for (int i = 0; i < n.length(); i++) {
            char cc = n.charAt(i);
            res = ((res * 10) % m + Integer.parseInt(String.valueOf(cc))) % m;
        }
        int gcd = ans(m, res);
        System.out.println(gcd);

    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t-- > 0) {
            int m = sc.nextInt();
            String n = sc.next();
            getAns(m, n);

        }
    }
}