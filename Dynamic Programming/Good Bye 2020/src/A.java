import java.util.Scanner;

public class A {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int test = in.nextInt();
        while (test-- > 0) {
            int n = in.nextInt();
            int [] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            int ans = 0, k;
            int [] b = new int[20000];
            for (int i = 0; i < 20000; i++) {
                b[i] = 1;
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    k = a[j] - a[i];
                    if (b[k] != 0) {
                        ans++;
                        b[k] = 0;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}
