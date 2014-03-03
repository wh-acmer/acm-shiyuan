import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner in =new Scanner(System.in);
		BigInteger dp[]=new BigInteger[1010];
		while(in.hasNext()){
			int n=in.nextInt();
			int k=in.nextInt();
			dp[0]=BigInteger.ONE;
			for(int i=1;i<=k;i++){
				for(int j=i;j<=n;j++){
					if(dp[j]==null) dp[j]=dp[j-i];
					else dp[j]=dp[j].add(dp[j-i]);
				}
			}
			System.out.println(dp[n]);
		}
	}
}
