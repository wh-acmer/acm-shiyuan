/*
    dp
    用小于等于号连接n个字符的关系大小，求方案数
    设dp[i][j]表示i个字符，分成j个等价类的方案数
    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])*j;
*/
import java.math.BigInteger;
import java.util.*;
public class Main{
    public static  void main(String args[]){
        Scanner cin=new Scanner(System.in);
        int T;
        T=cin.nextInt();
        while(T-->0){
            int n;
            n=cin.nextInt();
            BigInteger dp[][]=new BigInteger[n+1][n+1];
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++) dp[i][j]=BigInteger.ZERO;
            }
            /*  dp[i][j] 表示i个字母被分成了j个等价类后关系的方案数
                i j  0 1 2 3
                1    0 1 - -
                2    0 1 2 -
                3

             */
            dp[1][1]=BigInteger.ONE;
            for(int i=2;i<=n;i++){
                for(int j=1;j<=i;j++){
                    dp[i][j]=(dp[i-1][j].add(dp[i-1][j-1])).multiply(BigInteger.valueOf(j));
                }
            }
            BigInteger ans=BigInteger.ZERO;
            for(int i=1;i<=n;i++) ans=ans.add(dp[n][i]);
            System.out.println(ans);
        }
    }
}
