/*
dp[i][0] 表示以M结尾
dp[i][1] 表示以F结尾
dp[i][0]=dp[i-2][0]+dp[i-2][1]+dp[i-1][1];
dp[i][1]=dp[i-2][0]+dp[i-1][1];
*/
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner cin=new Scanner(System.in);
        BigInteger f[][]=new BigInteger[1010][2];
        f[1][0]=BigInteger.ONE;
        f[1][1]=BigInteger.ZERO;
        f[2][0]=BigInteger.ONE;
        f[2][1]=BigInteger.ONE;
        for(int i=3;i<1010;i++)
        {
            f[i][0]=f[i-2][0].add(f[i-2][1].add(f[i-1][1]));
            f[i][1]=f[i-1][1].add(f[i-2][0]);
        }
        while(cin.hasNext())
        {
            int n=cin.nextInt();
            System.out.println(f[n][0].add(f[n][1]));
        }

    }
}
