/*
    lucas
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
LL p,m,n;
LL Pow(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=(ans*a)%p;
        }
        else
        {
            b/=2;
            a=(a*a)%p;
        }
    }
    return ans;
}
LL C(LL n,LL m)
{
    if(n<m)
        return 0;
    LL ans=1;
    for(int i=1;i<=m;i++)
    {
        ans=ans*(((n-m+i)%p)*Pow(i,p-2)%p)%p;
    }
    return ans;
}
LL Lucas(LL n,LL m)
{
    if(m==0)
        return 1;
    return Lucas(n/p,m/p)*C(n%p,m%p)%p;
}
int main()
{
    while(scanf("%lld%lld%lld",&n,&m,&p)!=EOF)
    {
        printf("%lld\n",Lucas(n-m+1,m));
    }
    return 0;
}
