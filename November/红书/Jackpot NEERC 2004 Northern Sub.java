import java.math.*;
import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		BigInteger[] num=new BigInteger[16];
		while(in.hasNext()){
			int n=in.nextInt();
			BigInteger all=BigInteger.ONE;
			BigInteger ans=BigInteger.ZERO;
			BigInteger tmp;
			for(int i=0;i<n;i++){
				num[i]=in.nextBigInteger();
				tmp=all.gcd(num[i]);
				all=all.multiply(num[i]).divide(tmp);
			}
			for(int i=1;i<(1<<n);i++){
				int count=0;
				BigInteger cnt=BigInteger.ONE;
				for(int j=0;j<n;j++){
					if((i&(1<<j)) > 0){
						count++;
						tmp=cnt.gcd(num[j]);
						cnt=cnt.multiply(num[j]).divide(tmp);
					}
				}
				cnt=all.divide(cnt);
				if(count%2==1){
					ans=ans.add(cnt);
				}
				else{
					ans=ans.subtract(cnt);
				}
			}
			if(ans.compareTo(BigInteger.ONE)<0){
				ans=ans.multiply(BigInteger.valueOf(-1));
			}
			tmp=ans.gcd(all);
			ans=ans.divide(tmp);
			all=all.divide(tmp);
			System.out.println(ans);
			System.out.println(all);
		}
		in.close();
	}
}