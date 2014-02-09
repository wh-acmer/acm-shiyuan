/*
    water CRT
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
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
        long long tmp=x;
        x=y;
        y=tmp-a/b*y;
        return ans;
    }
}
int a[5],w[5];
long long M;
int CRT(int r)
{
    M=1;
    for(int i=1;i<=r;i++)
        M*=w[i];
    long long x0,y0,d;
    int ans=0;
    for(int i=1;i<=r;i++)
    {
        d=M/w[i];
        exgcd(d,w[i],x0,y0);
        ans=(ans+d*x0*a[i])%M;
    }
    if(ans<0)
        ans+=M;
    return ans;
}
int main()
{
    int tag=0;
    while(1)
    {
        for(int i=1;i<=3;i++)
            scanf("%d",&a[i]);
        int k;
        scanf("%d",&k);
        if(a[1]==-1&&a[2]==-1&&a[3]==-1&&k==-1)
            break;
        w[1]=23;
        w[2]=28;
        w[3]=33;
        int ans=CRT(3)-k;
        while(ans<=0)
            ans+=M;
        printf("Case %d: the next triple peak occurs in %d days.\n",++tag,ans);
    }
    return 0;
}
