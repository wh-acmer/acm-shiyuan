/*
    dp
*/
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static BigInteger min(BigInteger a,BigInteger b)
    {
        if(a.compareTo(b)<=0)
            return a;
        return b;
    }
    public static void main(String args[])
    {
        BigInteger dp[]=new BigInteger[65];
        Scanner cin=new Scanner(System.in);
        dp[1]=BigInteger.ONE;
        dp[2]=BigInteger.valueOf(3);
        for(int i=3;i<65;i++)
        {
            dp[i]=BigInteger.valueOf(2).pow(i).subtract(BigInteger.ONE);
            for(int j=1;j<i;j++)
                dp[i]=min(dp[i],dp[i-j].multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(2).pow(j).subtract(BigInteger.ONE)));
        }
        while(cin.hasNext())
        {
            int n=cin.nextInt();
            System.out.println(dp[n]);
        }
    }

}
