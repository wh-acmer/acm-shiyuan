#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 100005
#define mod 1000000007
long long f[maxn];
long long g[maxn];
inline void init()
{
    int cnt=0;
    for(int k=1;k*(3*k-1)/2<=maxn+1000;k++)
    {
        g[cnt++]=k*(3*k-1)/2;
        k*=-1;
        g[cnt++]=k*(3*k-1)/2;
        k*=-1;
    }
    f[0]=1;
    for(int i=1;i<maxn;i++)
    {
        int tmp=i;
        int pnt=0;
        f[i]=0;
        int tag=0;
        while(tmp>=g[pnt])
        {
            if((pnt/2)%2==0)
                f[i]+=f[i-g[pnt]];
            else f[i]-=f[i-g[pnt]];

            f[i]=(f[i]%mod+mod)%mod;
            pnt++;
        }
    }
}
inline int input()
{
    int ret=0;
    char c;
    c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
    return ret;
}
int main()
{
    init();
    int t;
    t=input();
    while(t--)
    {
        int n=input();
        printf("%I64d\n",f[n]);
    }
    return 0;
}
