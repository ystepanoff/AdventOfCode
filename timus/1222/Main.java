import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        BigInteger[] dp = new BigInteger[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = BigInteger.ONE;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                BigInteger t = dp[i - j].multiply(BigInteger.valueOf(j));
                if (t.compareTo(dp[i]) > 0) {
                    dp[i] = t;
                }
            }
        }
        System.out.println(dp[n].toString());
    }
}
