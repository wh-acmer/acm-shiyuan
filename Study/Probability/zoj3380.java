import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    static BigInteger[][] C=new BigInteger[110][110];
    static void init(){
        for(int i=0;i<110;i++)
        {
            C[i][0]=C[i][i]=BigInteger.ONE;
            for(int j=1;j<i;j++)
                C[i][j]=C[i-1][j-1].add(C[i-1][j]);
        }
    }
    public static  void main(String [] args){
        Scanner in =new Scanner(System.in);
        init();
        BigInteger[][] dp= new BigInteger[110][110];
        while(in.hasNext()){
            int l,m,n;
            m=in.nextInt();
            n=in.nextInt();
            l=in.nextInt();
            if(l>m){
                System.out.println("mukyu~");
                continue;
            }
            BigInteger total=BigInteger.valueOf(n).pow(m);
            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    dp[i][j]=BigInteger.ZERO;
                }
            }
            dp[0][0]=BigInteger.ONE;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                {
                    for(int k=0;k<l&&k<=j;k++)
                        dp[i][j]=dp[i][j].add(dp[i-1][j-k].multiply(C[m-(j-k)][k]));
                }
            BigInteger ans=BigInteger.ZERO;

            for(int i=1;i<=n;i++)
                ans=ans.add(dp[i][m]);
            ans=total.subtract(ans);
            BigInteger tmp=ans.gcd(total);
            System.out.println(ans.divide(tmp)+"/"+total.divide(tmp));
        }
    }
}
