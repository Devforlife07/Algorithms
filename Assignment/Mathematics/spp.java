import java.io.*;
import java.util.*;

public class spp {
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

    static long k;
    static ArrayList<Long> b = new ArrayList<>();
    static ArrayList<Long> c = new ArrayList<>();

    public static long compute(long n, long m) {
        ArrayList<Long> fi = new ArrayList<>();
        long sumk = 0;
        if (n == 0)
            return 0;
        if (n <= k) {
            for (int i = 0; i < n; i++) {
                sumk = (sumk + b.get(i)) % m;
            }
            return sumk;
        }
        int i = 0;
        // calculate sum of first k elements
        for (i = 0; i < k; i++) {
            sumk = (sumk + b.get(i)) % m;
        }
        // Construct Fi Vector
        fi.add(sumk);
        for (i = 1; i <= k; i++) {
            fi.add(b.get(i - 1));
        }
        ArrayList<ArrayList<Long>> T;
        // vector<vector<ll>> T(k + 2, vector<ll>(k + 2));
        for (i = 0; i < k + 1; i++) {
            for (ll j = 0; j < k + 1; j++) {
                if (i == 1) {
                    if (j == 1)
                        T[i][j] = 1;
                    else {
                        T[i][j] = c[k - j + 1];
                    }
                } else if (i == k + 1) {
                    if (j == 1)
                        T[i][j] = 0;
                    else {
                        T[i][j] = c[j - 2];
                    }
                } else {
                    if (j == (i + 1))
                        T[i][j] = 1;
                    else {
                        T[i][j] = 0;
                    }
                }
            }
        }

        vector<vector<ll>> res = pow(T, n - k, m);

        ll answer = 0;
        for (ll t = 1; t <= k + 1; t++) {
            answer = (answer + (res[1][t] * fi[t]) % m) % m;
        }
        return answer;
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t-- > 0) {

            k = sc.nextInt();
            long i = 0;
            long num = 0l;
            while (i < k) {
                num = sc.nextLong();
                b.add(num);
                i++;
            }
            i = 0;
            while (i < k) {
                num = sc.nextLong();
                c.add(num);
                i++;
            }
            long m, n, p;
            m = sc.nextLong();
            n = sc.nextLong();
            p = sc.nextLong();
            // cin >> m >> n >> p;
            System.out.println((compute(n, p) - compute(m - 1, p)));
            b.clear();
            c.clear();
        }
    }
}