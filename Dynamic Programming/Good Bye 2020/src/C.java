import java.util.Scanner;

public class C {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            char[] ch = in.next().toCharArray();
            int count = 0;
            for (int i = 1; i < ch.length; i++) {
                if (ch[i] == ch[i - 1]) {
                    ch[i] = '!';
                    count++;
                } else if (i > 1 && ch[i] == ch[i - 2]) {
                    ch[i] = '!';
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
