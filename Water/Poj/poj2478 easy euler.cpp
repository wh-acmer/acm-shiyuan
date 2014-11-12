// 简单求euler的累积和的个数
// 这个代码的用时较长
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=1000001;
long long euler[maxn];
void phi()
{
    for(int i=1;i<maxn;i++)
        euler[i]=i;
    for(int i=2;i<maxn;i+=2)
        euler[i]/=2;
    for(int i=3;i<maxn;i+=2)
        if(euler[i]==i)
            for(int j=i;j<maxn;j+=i)
                euler[j]=euler[j]/i*(i-1);
    euler[1]=0;
}
void solve()
{
    phi();
    euler[0]=0;
    for(int i=1;i<maxn;i++)
        euler[i]+=euler[i-1];
}
int main()
{
    solve();
    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        printf("%lld\n",euler[n]);
    }
    return 0;
}

// 再贴个用空间代替时间的代码
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1000001;
long long euler[maxn];
long long prime[maxn/3];//估摸着，这么写能省点内存
bool isprime[maxn];
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
    int n;
    while(scanf("%d",&n)!=EOF,n)
    {
        printf("%lld\n",euler[n]);
    }
    return 0;
}
