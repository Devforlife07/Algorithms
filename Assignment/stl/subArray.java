import java.util.*;

class subArray {
    static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n = sc.nextInt();
        int[] a = new int[n];
        int i = 0;
        while (i < n)
            a[i++] = sc.nextInt();
        int ans = 0;
        i = 0;
        while (i < n) {
            int j = i;
            Set<Integer> s = new HashSet<>();
            while (j < n) {
                if (!s.contains(a[j])) {
                    s.add(a[j]);
                    j++;
                } else
                    break;
            }
            // System.out.println("j=" + j);
            int temp = j - i;
            ans += (temp * (temp + 1)) / 2;
            i = j;

        }
        System.out.println(ans);

    }
}