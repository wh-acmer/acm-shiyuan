#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 10000010
int prime[664580];
bool vis[maxn];
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
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n_prime&&prime[i]<=n/2;i++)
        {
            if(prime[i]&&vis[n-prime[i]])
                ans++;
        }
        printf("Case %d: %d\n",cases,ans);
    }
    return 0;
}
