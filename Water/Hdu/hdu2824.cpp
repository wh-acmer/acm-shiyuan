#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=3000011;
long long euler[maxn];
long long prime[maxn/3];
bool isprime[maxn];
long long f[maxn];
void solve()
{
    int cnt=0;
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            prime[++cnt]=i;
            euler[i]=i-1;
        }
        for(int j=1;j<=cnt&&prime[j]*i<maxn;j++)
        {
            isprime[prime[j]*i]=0;
            if(i%prime[j]!=0)
                euler[i*prime[j]]=euler[i]*euler[prime[j]];
            else
            {
                euler[i*prime[j]]=euler[i]*prime[j];
                break;
            }
        }
    }
    euler[1]=0;
    for(int i=2;i<maxn;i++)
        euler[i]+=euler[i-1];
}
int main()
{
    solve();
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        printf("%I64d\n",euler[b]-euler[a-1]);
    }
    return 0;
}
