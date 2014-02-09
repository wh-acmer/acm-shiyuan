/*
˼·������n/phi(n)=1/��1-1/p1��* 1/��1-1/p2��* ... * 1/��1-1/pn������p�ĸ���Խ��Ļ������ֵ��Խ��
����ö��10^100�ڣ��������۳˵Ľ������Ų���60�
*/
import java.util.*;
import java.math.*;


public class Main {
    public static void main(String args[]){
        int maxn = 10000;
        boolean[] vis=new boolean[maxn];
        int[] prime = new int[maxn];
        int n_prime=0;
        Arrays.fill(vis,true);
        vis[0]=false;
        vis[1]=false;
        for(int i=2;i<maxn;i++)
            if(vis[i])
            {
                prime[++n_prime]=i;
                for(int j=2*i;j<maxn;j+=i)
                    vis[j]=false;
            }
        BigInteger[] ans =new BigInteger[60];
        ans[0]=BigInteger.ONE;
        for(int i=1;i<60;i++)
        {
            ans[i]=ans[i-1].multiply(new BigInteger(Integer.toString(prime[i])));
            //System.out.println(i+" "+ans[i].toString().length()+" "+ans[i]);
            if((ans[i].toString()).length()>105)
            {
                //System.out.println(i);
                break;
            }
        }
        BigInteger n;
        Scanner cin = new Scanner(System.in);
        int t;
        t=cin.nextInt();
        while(t-- >0)
        {
            n=cin.nextBigInteger();
            for(int i=0;i<60;i++)
                if(ans[i+1].compareTo(n)>0)
                {
                    System.out.println(ans[i]);
                    break;
                }
        }
    }
}
