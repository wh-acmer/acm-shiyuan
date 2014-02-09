/*
    math
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[11],b[11],n;
long long gcd(long long a,long long b)
{
    return !b?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
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
        long long tmp=x;
        x=y;
        y=tmp-a/b*y;
        return ans;
    }
}
bool solve()
{
    a[0]=a[1],b[0]=b[1];
    for(int i=2;i<=n;i++)
    {
        long long a0=b[0];
        long long b0=b[i];
        long long c0=a[i]-a[0];
        long long x0,y0;
        long long r=gcd(a0,b0);
        if(c0%r!=0)
            return false;
        else
        {
            a0/=r;
            b0/=r;
            c0/=r;
            exgcd(a0,b0,x0,y0);
            x0*=c0;
            x0=(x0%b0+b0)%b0;
            a[0]=b[0]*x0+a[0];
            b[0]=b[0]*b0;
        }
    }
    return true; // a[0]为小于[b1,b2...bn]的非负整数解
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N;
        scanf("%d%d",&N,&n);
        long long tag=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            tag=lcm(tag,b[i]);
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        long long ans=0;
        long long cnt;
        if(solve())
        {
            cnt=a[0];
            //printf("%lld........%lld\n",cnt,tag);
            if(cnt<N)
            {
                ans=1+(N-cnt)/tag;
            }
            if(cnt==0)
                ans--;//0不是正整数
        }
        printf("%lld\n",ans);
    }
    return 0;
}
