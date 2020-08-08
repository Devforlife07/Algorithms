import java.io.*;
import java.util.*;

public class fibosum {
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

    static long MOD = 1000000007;

    public static long[][] mul(long[][] k, long[][] l) {
        long[][] res = new long[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int x = 0; x < 3; x++) {
                    res[i][j] = (res[i][j] + (k[i][x] * l[x][j]) % MOD) % MOD;
                }
            }
        }
      

        return res;
    }

    public static long[][] pow(long[][] T, long n) {
        if (n == 1)
            return T;
        if ((n & 1) == 1) {
            return mul(T, pow(T, n - 1));
        } else {
            long[][] res = pow(T, n / 2);
            return mul(res, res);
        }

    }

    public static long compute(long n) {
        long[][] T = { { 1, 1, 1 }, { 0, 0, 1 }, { 0, 1, 1 } };
        long[] fi = { 1, 0, 1 };
        if (n <= 0)
            return 0;
        else if (n == 1)
            return 1;
        long[][] res = pow(T, n - 1);
        long ans = 0l;
        for (int i = 0; i < 3; i++) {
            ans = (ans + (res[0][i] * fi[i]) % MOD) % MOD;
        }
        return ans;
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = sc.nextInt();
        while (t-- > 0) {
            long m = sc.nextLong();
            long n = sc.nextLong();
            long ans = (compute(n) % MOD - compute(m - 1) % MOD + MOD) % MOD;
            // long ans = (compute(m)) % MOD;
            out.println(ans);
            out.flush();
        }
    }
}