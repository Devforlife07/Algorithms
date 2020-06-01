import java.util.*;
import java.io.*;

class bostonNumber {
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

    public static long sum(long n) {
        long sum = 0;
        if (n < 10) {
            sum = n;
        } else {
            while (n != 0) {
                int rem = (int) n % 10;
                sum += rem;
                n /= 10;
            }
        }
        return sum;
    }

    public static long sum_of_factor(long n, long x) {
        long sum = 0;
        while (n % x == 0) {
            sum += x;
            n /= x;
        }
        return sum;
    }

    public static boolean isPrime(long n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if ((n % 2) == 0 || (n % 3) == 0) {
            return false;
        }
        for (long i = 5; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        // System.out.println(isPrime(37));
        FastReader sc = new FastReader();
        long n = sc.nextLong();
        long sum_of_num = sum(n);
        long sum_of_factor = 0;
        long copy = n;
        for (long i = 2; i * i <= copy; i++) {
            if (isPrime(i)) {
                // System.out.println(i);
                while (copy % i == 0) {
                    sum_of_factor += sum(i);
                    copy /= i;
                }
            }
        }
        if (copy > 2) {
            sum_of_factor += sum(copy);
        }
        // System.out.println(sum_of_factor);
        int ans = sum_of_factor == sum_of_num ? 1 : 0;
        System.out.println(ans);
    }

}