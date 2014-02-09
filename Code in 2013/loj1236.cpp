/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 10000010
bool vis[maxn];
int prime[665000];
int n_prime=0;
void Prime()
{
    memset(vis,1,sizeof(vis));
    vis[0]=vis[1]=0;
    for(int i=2;i<maxn;i++)
    {
        if(vis[i])
        {
            prime[++n_prime]=i;
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=0;
        }
    }
    //printf("%d %d\n",n_prime,prime[n_prime]);
}
int main()
{
    Prime();
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        long long n;
        scanf("%lld",&n);
        long long ans=1;
        for(int i=1;i<=n_prime&&prime[i]<=sqrt(n);i++)
        {
            long long cnt=0;
            if(n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    cnt++;
                }
                ans*=(2*cnt+1);
            }
        }
        if(n>1)
            ans*=3;
        ans++;
        ans/=2;
        printf("Case %d: %lld\n",cases,ans);
    }
    return 0;
}
