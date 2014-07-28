import java.math.*;
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            long n = in.nextLong();
            long d = in.nextLong();
            BigInteger a=BigInteger.valueOf(d*(n+4));
            a=a.multiply(BigInteger.valueOf((d - 1) * (n + 4)));
            BigInteger b=BigInteger.valueOf(n).pow((int) d);
            b=b.multiply(BigInteger.valueOf(18));
            BigInteger c=a.gcd(b);
            a=a.divide(c);
            b=b.divide(c);
            if(b.equals(BigInteger.ONE)){
                System.out.println(a);
            }
            else{
                System.out.println(a + "/" + b);
            }
        }
        in.close();
    }
}
