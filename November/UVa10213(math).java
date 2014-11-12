// How Many Pieces of Land ?
// http://uva.onlinejudge.org/external/102/10213.pdf

import java.math.BigInteger;
import java.util.*;
public class Main {
	public static BigInteger C(int n,int m){
		if(n<m) return BigInteger.ZERO;
		BigInteger ans = BigInteger.ONE;
		if( n-m < m ){
			m = n-m;
		}
		for( int i = 1 ; i <= m ; i++ ){
			ans = ans.multiply( BigInteger.valueOf(n+1-i) );
			ans = ans.divide( BigInteger.valueOf(i) );
		}
		return ans;
	}
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while( T-- >0 ){
			int n = in.nextInt();
			BigInteger ans = BigInteger.ONE;
			ans = ans.add( C(n,2) );
			ans = ans.add( C(n,4) );
			System.out.println( ans );
		}
	}
}
