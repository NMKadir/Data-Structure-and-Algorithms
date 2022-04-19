import java.util.*;

public class B {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int test = in.nextInt();
        while (test-- > 0) {
            int n = in.nextInt();
            int [] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            Set <Integer> s = new TreeSet<Integer>();
            for (int i = 0; i < n; i++) {
                if (s.contains(a[i])) {
                    a[i]++;
                }
                s.add(a[i]);
            }
            System.out.println(s.size());
        }
    }
}
