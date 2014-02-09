/*
    lucas
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 200010
typedef long long LL;
LL m,n,p;
LL fac[maxn];
void init(LL p)
{
    fac[0]=1;
    for(int i=1;i<=p;i++) // Ð´³Éi<maxn ¾ÍTLEÁË
        fac[i]=(fac[i-1]*i)%p;
}
LL Pow(LL a,LL b,LL mod)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=(ans*a)%mod;
        }
        else
        {
            b/=2;
            a=(a*a)%mod;
        }
    }
    return ans;
}
LL C(LL n,LL m)
{
    if(n<m)
        return 0;
    LL ans=fac[n]*Pow(fac[m]*fac[n-m]%p,p-2,p)%p;
    return ans;
}
LL Lucas(LL n,LL m)
{
    if(m==0)
        return 1;
    return (Lucas(n/p,m/p)*C(n%p,m%p))%p;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&n,&m,&p);
        init(p);
        if(m>n)
            swap(m,n);
        printf("%I64d\n",Lucas(n+m,m));
    }
    return 0;
}
