/*
    dp
    ��С�ڵ��ں�����n���ַ��Ĺ�ϵ��С���󷽰���
    ��dp[i][j]��ʾi���ַ����ֳ�j���ȼ���ķ�����
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
            /*  dp[i][j] ��ʾi����ĸ���ֳ���j���ȼ�����ϵ�ķ�����
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
