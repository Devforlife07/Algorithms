import java.io.*;
import java.util.*;

public class divisiblesubarrays {
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

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            HashMap<Long, Long> map = new HashMap<>();
            map.put(0l, 1l);
            long sum = 0;
            for (int i = 0; i < n; i++) {
                long num = sc.nextLong();
                sum = (sum + num) % n;
                long mod = (sum + n) % n;
                if (map.containsKey(mod)) {
                    map.put(mod, map.get(mod) + 1);
                } else {
                    map.put(mod, 1l);
                }

            }
            long res = 0;
            // System.out.println(map);
            for (Map.Entry<Long, Long> ent : map.entrySet()) {

                res += ((ent.getValue() * (ent.getValue() - 1)) / 2);

            }
            System.out.println(res);
            map.clear();
        }
    }
}