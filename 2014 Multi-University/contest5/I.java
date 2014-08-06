import java.math.*;
import java.util.*;
public class Main{
    static HashMap<BigInteger,BigInteger>mp=new HashMap<BigInteger, BigInteger>();
    static BigInteger solve(BigInteger n){
        if(mp.containsKey(n)) return mp.get(n);
        if(n.equals(BigInteger.ZERO)){
            mp.put(n,BigInteger.ZERO);
            return BigInteger.ZERO;
        }
        if(n.equals(BigInteger.ONE)){
            mp.put(n,BigInteger.ZERO);
            return BigInteger.ZERO;
        }
        if(n.equals(BigInteger.valueOf(2))){
            mp.put(n,BigInteger.ZERO);
            return BigInteger.ZERO;
        }
        if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)){
            BigInteger nn=n.divide(BigInteger.valueOf(2));
            BigInteger y=solve(nn);
            nn=nn.subtract(BigInteger.valueOf(1));
            y=y.add(solve(nn));
            y=y.multiply(BigInteger.valueOf(2));
            y=y.add(BigInteger.valueOf(4).multiply(nn));
            mp.put(n,y);
            return y;
        }
        else{
            BigInteger nn=n.subtract(BigInteger.valueOf(1));
            nn=nn.divide(BigInteger.valueOf(2));
            BigInteger x=solve(nn);
            x=x.multiply(BigInteger.valueOf(4));
            BigInteger y=x.add(BigInteger.valueOf(6).multiply(nn));
            mp.put(n,y);
            return y;
        }
    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        HashMap<BigInteger,BigInteger>mp=new HashMap<BigInteger, BigInteger>();
        while(in.hasNext()){
            BigInteger x=in.nextBigInteger();
            System.out.println(solve(x));
        }
        in.close();
    }
}
