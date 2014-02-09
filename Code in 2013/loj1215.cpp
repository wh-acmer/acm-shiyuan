/*
    water
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 1000010
int prime[78501];
int num[78501];
int cnt[78501];
int n_prime=0;
int vis[maxn];
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
long long Pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans*=a;
        }
        else
        {
            b/=2;
            a*=a;
        }
    }
    return ans;
}
int main()
{
    Prime();
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        long long a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        memset(num,0,sizeof(num));
        memset(cnt,0,sizeof(cnt));
        printf("Case %d: ",cases);
        for(int i=1;i<=n_prime;i++)
        {
            if(prime[i]>a)
                break;
            if(a%prime[i]==0)
            {
                int tmp=0;
                while(a%prime[i]==0)
                {
                    a/=prime[i];
                    tmp++;
                }
                num[i]=max(num[i],tmp);
            }
        }
        for(int i=1;i<=n_prime;i++)
        {
            if(prime[i]>b)
                break;
            if(b%prime[i]==0)
            {
                int tmp=0;
                while(b%prime[i]==0)
                {
                    b/=prime[i];
                    tmp++;
                }
                num[i]=max(num[i],tmp);
            }
        }
        int tag=1;
        for(int i=1;i<=n_prime;i++)
        {
            if(prime[i]>l)
                break;
            if(l%prime[i]==0)
            {
                while(l%prime[i]==0)
                {
                    l/=prime[i];
                    cnt[i]++;
                }
            }
        }
        long long tmp=l;
        for(int i=1;i<=n_prime;i++)
        {
            if(cnt[i]>num[i])
                tmp*=Pow(prime[i],cnt[i]);
            else if(cnt[i]<num[i])
            {
                tag=0;
                break;
            }
        }
        if(tag)
            printf("%lld\n",tmp);
        else
            printf("impossible\n");
    }
    return 0;
}
