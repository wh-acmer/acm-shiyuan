/*
    模版
*/
import java.util.*;
import java.math.*;

class fraction{
    BigInteger a, b;
    public fraction(){
        a = new BigInteger("0");
        b = new BigInteger("1");
    }

    fraction( BigInteger a0, BigInteger b0){
        this.a = a0; this.b = b0;
    }
    void reduction(){
        BigInteger tmp = a.gcd( b );
        a = a.divide( tmp );
        b = b.divide( tmp );
        if( b.compareTo( BigInteger.ZERO ) == - 1 )
        {
            b = b.multiply( BigInteger.valueOf( -1 ));
            a = a.multiply( BigInteger.valueOf( -1 ));
        }
    }
    fraction add( fraction t ){
        fraction tmp = new fraction( a.multiply( t.b ).add( b.multiply( t.a )) , b.multiply(t.b) );
        tmp.reduction();
        return tmp;
    }
    fraction sub( fraction t ){
        fraction tmp = new fraction( a.multiply( t.b ).subtract( b.multiply( t.a )) , b.multiply(t.b) );
        tmp.reduction();
        return tmp;
    }
    fraction mult( fraction t){
        fraction tmp = new fraction( a.multiply( t.a ), b.multiply( t.b ));
        tmp.reduction();
        return tmp;
    }
    fraction div( fraction t){
        fraction tmp = new fraction( a.multiply( t.b ), b.multiply( t.a ));
        tmp.reduction();
        return tmp;
    }
    public void abs(){
        if( this.a.compareTo( BigInteger.ZERO ) == - 1 ){
            this.a = this.a.multiply( BigInteger.valueOf( -1 ));
        }
    }
    void out(){
        this.reduction();
        if( b.compareTo( BigInteger.ONE ) == 0 )
            System.out.println(a);
        else
            System.out.println(a+"/"+b);
    }

    boolean biger( fraction p ){
        fraction tmp = new fraction ( a, b );
        fraction t = new fraction(p.a,p.b);
        //t = p;
        tmp.reduction();
        if( tmp.a.compareTo( BigInteger.ZERO ) == - 1 ){
            tmp.a = tmp.a.multiply( BigInteger.valueOf( -1 ));
        }
        if( t.a.compareTo( BigInteger.ZERO ) == - 1 ){
            t.a = t.a.multiply( BigInteger.valueOf( -1 ));
        }
        tmp = tmp.sub( t );
        return tmp.a.compareTo( BigInteger.ZERO ) > -1;
    }

}

public class Main{

    public static void lup_solve( fraction x[],fraction y[], fraction L[][], fraction U[][],int pi[],fraction b[],int n)
    {
        int i, j;
        fraction z = new fraction( BigInteger.ZERO , BigInteger.ONE);
        fraction sum = z;//double sum;
        for ( i = 0 ; i < n ; i ++ ){
            sum = z; //sum = 0;
            for ( j = 0 ; j < i ; j ++ ){
                sum = sum.add( L[i][j].mult( y[j] ));//sum += L[i][j] * y[ j ];
            }
            y[i] = b[ pi[i] ].sub( sum );//y[i] = b[ pi[i] ] - sum;
        }
        for ( i = n - 1 ; i >= 0 ; i -- ){
            sum = z ; //sum = 0;
            for ( j = i + 1 ; j < n ; j ++ ){
                sum = sum.add( U[i][j].mult( x[j] ));//sum += U[i][j] * x[ j ];
            }
            x[i] = (y[i].sub( sum )).div( U[i][i] );//x[i] = (y[i] - sum)/U[i][i];
        }
    }

    public static int lup_decomposition( fraction a[][] , int n , int pi[] )
    {
        int i, j, k, k1 = 0 ;
        fraction p = new fraction(BigInteger.valueOf(0), BigInteger.ONE ), z = new fraction( BigInteger.valueOf(0), BigInteger.ONE );
        for ( i = 0 ; i < n ; i ++ )
            pi[i] = i;// 置换

        for ( k = 0 ; k < n ; k ++ ){
            p = z;
            for ( i = k ; i < n ; i ++ )
            {
                if(  a[i][k].biger( p ) )
                {
                    p = new fraction( a[i][k].a,a[i][k].b) ;
                    k1 = i;
                }
            }
            if( p.a.compareTo( BigInteger.ZERO ) == 0 ){
                return 0 ;// error
            }
            fraction tmp;

            int t = pi[ k ]; pi[ k ] = pi[ k1 ]; pi[k1] = t;
            for ( i = 0 ; i < n ; i ++ ){
                tmp = a[ k ][i];  a[ k ][i] = a[ k1 ][i];  a[k1][i] = tmp;
            }//swap( a[k][i], a[k1][i] );
            for ( i = k + 1 ; i < n ; i ++ )
            {
                a[i][k] = a[i][k].div( a[k][k] );
                for ( j = k + 1 ; j < n ; j ++ )
                    a[i][j] = a[i][j].sub( a[i][k].mult(a[k][j]));// - a[i][k] * a[k][j] ;
            }
        }
        return 1;
    }

    public static void check(fraction a[][], fraction x[], int n){
        int i, j;
        fraction sum, z = new fraction( BigInteger.ZERO , BigInteger.ONE);
        for ( i = 0 ;  i < n ; i++ ){
            sum = z;
            for ( j = 0 ;j < n ; j ++ )
            {
                sum = sum.add( a[i][j].mult( x[j] ));
            }
            sum.out();
        }
    }

    public static void main(String[] agrs){
        Scanner cin = new Scanner( System.in );
        int i, j;
        int n;
        while( cin.hasNextInt() )
        {
            //任何函数都要和一个class相连
            n = cin.nextInt();
            int pi[] = new int[n];
            fraction a[][] = new fraction[n][n];
            fraction aa[][] = new fraction[n][n];
            fraction B[] = new fraction[n];
            fraction x[] = new fraction[n];
            fraction y[] = new fraction[n];

            for ( i = 0 ; i < n ; i ++ )
            {
                for ( j = 0 ;j < n ; j ++ ){
                    a[i][j] = new fraction( BigInteger.valueOf(0),BigInteger.valueOf(1));
                    a[i][j].a = cin.nextBigInteger();
                    aa[i][j] = new fraction( BigInteger.valueOf(0),BigInteger.valueOf(1));
                    aa[i][j] = a[i][j];
                }
                B[i] = new fraction( BigInteger.valueOf(0),BigInteger.valueOf(1));
                B[i].a = cin.nextBigInteger();
                x[i] = new fraction( BigInteger.valueOf(0),BigInteger.valueOf(1));
                y[i] = new fraction( BigInteger.valueOf(0),BigInteger.valueOf(1));
            }
            if( 1 == lup_decomposition( a, n, pi) )
            {
                lup_solve( x, y, a, a, pi, B, n);
                for ( i = 0 ;i < n; i ++)
                    x[i].out();
                //check( aa, x, n);
            }
            else
            {
                System.out.println("No solution.");
            }
            System.out.println();
        }
    }
}
