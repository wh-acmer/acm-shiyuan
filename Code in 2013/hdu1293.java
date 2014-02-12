import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        Scanner cin=new Scanner(System.in);
        BigInteger dp[][]=new BigInteger[1010][3];
        for(int i=0;i<3;i++)
            dp[1][i]=BigInteger.ONE;
        for(int i=2;i<1010;i++)
        {
            dp[i][0]=dp[i-1][0].add(dp[i-1][1].add(dp[i-1][2]));
            dp[i][1]=dp[i-1][0].add(dp[i-1][1]);
            dp[i][2]=dp[i-1][0].add(dp[i-1][2]);
        }
        while(cin.hasNext())
        {
            int n=cin.nextInt();
            System.out.println(dp[n][0].add(dp[n][1].add(dp[n][2])));
        }

    }
}
