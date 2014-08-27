import java.math.*;
import java.util.*;
public class Solution{
    public static void main(String args[]){
         Scanner in = new Scanner(System.in);
         while(in.hasNext()){
             int n=in.nextInt();
             int K=in.nextInt();
             int w[]=new int[n];
             int b[]=new int[n];
             int num_w=0,num_b=0;
             w[num_w++]=n;
             for(int i=n-2;i>=1;i-=2){
                 w[num_w++]=i;
                 w[num_w++]=i;
             }
             for(int i=n-1;i>=1;i-=2){
                 b[num_b++]=i;
                 b[num_b++]=i;
             }
             Arrays.sort(w,0,num_w);
             Arrays.sort(b,0,num_b);
             BigInteger[][] dp=new BigInteger[2][n+1];
             BigInteger[][] dq=new BigInteger[2][n+1];
             for(int i=0;i<2;i++){
                 for(int j=0;j<=n;j++){
                     dp[i][j]=BigInteger.ZERO;
                     dq[i][j]=BigInteger.ZERO;
                 }
             }
             dp[0][0]=dq[0][0]=BigInteger.ONE;
             int x=1,y=1;
             for(int i=0;i<num_w;i++){
                 for(int j=0;j<=i+1;j++){
                     dp[x][j]=dp[x^1][j];
                 }
                 for(int j=1;j<=i+1 && w[i]-(j-1)>=0;j++){
                     dp[x][j]=dp[x][j].add(dp[x^1][j-1].multiply(BigInteger.valueOf(w[i]-(j-1))));
                 }
                 x^=1;
             }
             x^=1;
             for(int i=0;i<num_b;i++){
                 for(int j=0;j<=i+1;j++){
                     dq[y][j]=dq[y^1][j];
                 }
                 for(int j=1;j<=i+1 && b[i]-(j-1)>=0;j++){
                     dq[y][j]=dq[y][j].add(dq[y^1][j-1].multiply(BigInteger.valueOf(b[i]-(j-1))));
                 }
                 y^=1;
             }
             y^=1;
             BigInteger ans=BigInteger.ZERO;
             for(int i=0;i<=num_w && i<=K;i++){
                 if(K-i<=num_b){
                    ans=ans.add(dp[x][i].multiply(dq[y][K-i]));
                 }
             }
             System.out.println(ans);
         }
    }
}
