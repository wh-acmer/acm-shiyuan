/*
    质因数分解
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 10010
int vis[maxn];
int prime[maxn];
int n_prime=0;
void Prime()
{
    memset(vis,1,sizeof(vis));
    vis[0]=vis[1]=0;
    for(int i=2;i<maxn;i++)
        if(vis[i])
        {
            prime[++n_prime]=i;
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=0;
        }
    //cout<<n_prime<<":"<<prime[n_prime]<<endl;
}
string multi(string a,long long b)
{
    long long r=0;
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
long long get(long long n,long long p)
{
    long long ans=0,pnt=p;
    while(pnt<=n)
    {
        ans+=n/pnt;
        pnt*=p;
    }
    return ans;
}
int main()
{
    Prime();
    long long n;
    while(cin>>n)
    {
        if(n==0)
            break;
        string ans="1";
        for(int i=1;i<=n_prime;i++)
        {
            if(prime[i]>n)
                break;
            long long tmp=get(n,prime[i]);
            tmp*=2;
            tmp++;
            ans=multi(ans,tmp);
        }
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
