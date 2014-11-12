#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 1000010
#define mod 1000003
long long fac[maxn];
void Fac()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
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
        long long t=x;
        x=y;
        y=t-a/b*y;
        return ans;
    }
}
/// C(n,k) = n! / ( k! * (n-k)! )
int main()
{
    Fac();
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        long long k,n;
        scanf("%lld%lld",&n,&k);
        long long tmp=(fac[k]*fac[n-k])%mod;
        long long ans;
        long long kk;
        exgcd(tmp,mod,ans,kk);
        while(ans<0)
            ans+=mod;
        ans%=mod;
        ans=(ans*fac[n])%mod;
        printf("Case %d: ",cases);
        printf("%lld\n",ans);
    }
    return 0;
}
