/*
    exgcd
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ans=exgcd(b,a%b,x,y);
        long long t=x;
        x=y;
        y=t-a/b*y;
        return ans;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,k;
        scanf("%lld%lld",&x,&k);
        long long a=(long long)floor(x*1.0/k);
        long long b=(long long)ceil(x*1.0/k);

        /// ·½³Ì a*p+b*q=x

        long long p,q;
        exgcd(a,b,p,q);
        p*=x;
        p%=b;
        q=x-p*a;
        q/=b;
        printf("%lld %lld\n",p,q);
    }
    return 0;
}
