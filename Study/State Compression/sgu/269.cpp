import java.util.*;
import java.math.*;
public class Solution{
    public static void main(String[] args){
        BigInteger[][] dp = new BigInteger[2][255];
        int[] a = new int[255];
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            int n = in.nextInt();
            int K = in.nextInt();
            for(int i=1;i<=n;i++) a[i]=in.nextInt();
            Arrays.sort(a,1,n+1);
            Arrays.fill(dp[0],BigInteger.ZERO);
            Arrays.fill(dp[1],BigInteger.ZERO);
            dp[0][0]=BigInteger.ONE;
            int now=1;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=i;j++){
                     dp[now][j]=dp[now^1][j];
                }
                for(int j=1;j<=K && j<=i;j++){
                    dp[now][j]=dp[now][j].add(dp[now^1][j-1].multiply(BigInteger.valueOf(a[i]-(j-1))));
                }
                now^=1;
            }
            System.out.println(dp[now^1][K]);
        }
        in.close();
    }
}
