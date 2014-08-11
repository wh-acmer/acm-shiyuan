import java.util.*;
import java.math.*;
public class Main {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        int T=in.nextInt();
        while(T-->0){
            int n=in.nextInt();
            BigInteger x,C=BigInteger.ONE,ans=BigInteger.ZERO;
            int tag=1-n%2;
            for(int i=0;i<n;i++){
                x=in.nextBigInteger();
                if(i%2==tag)
                    ans=ans.add(x.multiply(C));
                else
                    ans=ans.subtract(x.multiply(C));
                C=C.multiply(BigInteger.valueOf(n-1-i)).divide(BigInteger.valueOf(i+1));
            }
            System.out.println(ans);
        }
        in.close();
    }
}
