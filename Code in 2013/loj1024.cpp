/*
    water + ¸ß¾«¶È
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define maxn 10005
int vis[maxn];
int prime[maxn];
int num[maxn];
int cnt[maxn];
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
string multi(string a,int b)
{
    int r=0;
    for(int i=0;i<a.size();i++)
    {
        r+=(a[i]-'0')*b;
        a[i]=(r%10+48);
        r/=10;
    }
    while(r)
    {
        a+=(r%10+'0');
        r/=10;
    }
    return a;
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
        memset(num,0,sizeof(num));
        while(n--)
        {
            int x;
            scanf("%d",&x);
            memset(cnt,0,sizeof(cnt));
            for(int i=1;i<=n_prime&&x>=prime[i];i++)
            {
                if(x%prime[i]==0)
                {
                    while(x%prime[i]==0)
                    {
                        x/=prime[i];
                        cnt[i]++;
                    }
                }
                num[i]=max(num[i],cnt[i]);
            }
        }
        string ans="1";
        for(int i=1;i<=n_prime;i++)
            for(int j=1;j<=num[i];j++)
                ans=multi(ans,prime[i]);
        printf("Case %d: ",cases);
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
