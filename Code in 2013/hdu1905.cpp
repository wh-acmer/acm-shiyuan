/*
    water
*/
#include <stdio.h>
#include <stdlib.h>
typedef unsigned __int64 hi;
hi gcd(hi a,hi b)
{
    while(a)
    {
        hi c=b%a;
        b=a;
        a=c;
    }
    return b;
}
hi product_mod(hi a,hi b,hi c)
{
    hi r,d;
    r=0;
    d=a;
    while(b>0)
    {
        if(b&1) r=(r+d)%c;
        d=(d+d)%c;
        b>>=1;
    }
    return r;
}
hi power_mod(hi a,hi b,hi c)
{
    hi r=1,d=a;
    while(b)
    {
        if(b&1) r=product_mod(r,d,c);
        d=product_mod(d,d,c);
        b>>=1;
    }
    return r;
}
hi random()
{
    hi a=rand();
    a*=rand();
    a*=rand();
    a*=rand();
    return a;
}
int pri[]={2,3,5,7,11,13,17,19,23,29};
bool isprime(hi n)
{
    if(n<2)
        return false;
    if(n==2)
        return true;
    if(!(n&1))
        return false;
    hi k=0,i,j,m,a;
    m=n-1;
    while(m%2==0)
        m=(m>>1),k++;
    for(i=0;i<10;i++)
    {
        if(pri[i]>=n) return true;
        a=power_mod(pri[i],m,n);
        if(a==1)
            continue;
        for(j=0;j<k;j++)
        {
            if(a==n-1) break;
            a=product_mod(a,a,n);
        }
        if(j<k)
            continue;
        return false;
    }
    return true;
}
hi pollard_rho(hi c,hi n)
{
    hi i,x,y,k,d;
    i=1;
    x=rand()%n;
    y=x;
    k=2;
    do
    {
        i++;
        d=gcd(n+y-x,n);
        if(d>1&&d<n) return d;
        if(i==k) y=x,k*=2;
        x=(product_mod(x,x,n)+n-c)%n;
    }while(y!=x);
    return n;
}

__int64 mod(__int64 a,__int64 b,__int64 n)
{
    __int64 ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans%n*a)%n;
        a=(a%n*a)%n;
        b/=2;
    }
    return ans;
}
int main()
{
    __int64 a,p;
    while(scanf("%I64d%I64d",&p,&a),p+a)
    {
        if(isprime(p))
        {
            printf("no\n");
            continue;
        }
        if(mod(a,p,p)==a)
        {
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }
    return 0;
}
