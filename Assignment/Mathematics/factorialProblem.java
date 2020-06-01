import java.io.*;
import java.util.*;

public class factorialProblem {
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

    public static boolean isPrime(long n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 4 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if ((n % i == 0) || (n % (i + 2) == 0))
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        HashSet<Long> set = new HashSet<>();
        while (t > 0) {
            HashMap<Long, Long> map = new HashMap<>();
            long n = sc.nextLong();
            long k = sc.nextLong();
            long copy = k;
            for (long i = 2; i * i <= copy; i++) {
                if (set.contains(i)) {
                    long c = 0;
                    while (copy % i == 0) {
                        c++;
                        copy /= i;
                    }
                    if (c > 0) {
                        map.put(i, c);
                    }
                } else {
                    if (isPrime(i)) {
                        set.add(i);
                        long c = 0;
                        while (copy % i == 0) {
                            c++;
                            copy /= i;
                        }
                        if (c > 0) {
                            map.put(i, c);
                        }
                    }
                }
            }
            if (copy >= 2) {
                map.put(copy, 1l);
            }
            HashMap<Long, Long> count = new HashMap<>();
            for (Map.Entry<Long, Long> ent : map.entrySet()) {
                long curr = ent.getKey();
                long coun = 0;
                while (curr <= n) {
                    coun += n / curr;
                    curr = curr * ent.getKey();

                }
                count.put(ent.getKey(), coun);

            }
            long min = Integer.MAX_VALUE;
            for (Map.Entry<Long, Long> temp : count.entrySet()) {
                long c = map.get(temp.getKey());
                if ((temp.getValue() / c) < min) {
                    min = temp.getValue() / c;
                }
            }
            System.out.println(min);
            t--;
        }
    }

}