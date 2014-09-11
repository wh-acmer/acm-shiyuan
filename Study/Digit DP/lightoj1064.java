import java.util.*;
import java.math.*;
public class Main{
    public static  BigInteger[][] dp=new BigInteger[26][310];
    public static BigInteger dfs(int n,int sum){
        if(n==0){
            if(sum-150<=0){
                return  BigInteger.ONE;
            }
            else{
                return BigInteger.ZERO;
            }
        }
        if(dp[n][sum]!=BigInteger.valueOf(-1)){
            return dp[n][sum];
        }
        BigInteger ans=BigInteger.ZERO;
        for(int i=1;i<=6;i++){
            ans=ans.add(dfs(n-1,sum-i));
        }
        return dp[n][sum]=ans;
    }
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        for(int i=0;i<=25;i++){
            for(int j=0;j<310;j++){
                dp[i][j]=BigInteger.valueOf(-1);
            }
        }
        int T=in.nextInt();
        for(int cas=1;cas<=T;cas++){
            int n=in.nextInt();
            int x=in.nextInt();
            BigInteger pi=dfs(n,x+150);
            BigInteger ka=BigInteger.ONE;
            for(int i=1;i<=n;i++){
                ka=ka.multiply(BigInteger.valueOf(6));
            }
            BigInteger g=pi.gcd(ka);
            pi=pi.divide(g);
            ka=ka.divide(g);
            System.out.print("Case "+cas+": ");
            if(ka.equals(BigInteger.valueOf(1))){
                System.out.println(pi);
            }
            else{
                System.out.println(pi+"/"+ka);
            }
        }
        in.close();
    }
}
