import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		BigInteger dp[] = new BigInteger[101];
		dp[0]=BigInteger.ONE; dp[1]=BigInteger.ONE;
		for(int i=2;i<101;i++){
			dp[i]=BigInteger.ZERO;
			for(int j=i-1;j>=0;j--)
				dp[i]=dp[i].add(dp[j].multiply(dp[i-1-j]));
		}
		while(in.hasNext()){
			int n=in.nextInt();
			if(n==-1) break;
			System.out.println(dp[n]);
		}
	}
}
