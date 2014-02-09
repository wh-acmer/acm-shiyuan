/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 1000001
int tag[maxn];
int gcd(int a,int b)
{
    return !b?a:gcd(b,a%b);
}
int x,y,z;
int n;
void solve()
{
    int ans=0,total=0;
    memset(tag,0,sizeof(tag));
    int tmp=(int)sqrt(n*1.0);
    for(int i=1;i<=tmp;i++)
    {
        for(int j=i+1;j<=tmp;j+=2)
        {
            if(i*i+j*j>n)
                break;
            if(i%2!=j%2)
            {
                if(gcd(i,j)==1)
                {
                    x=j*j-i*i;
                    y=2*i*j;
                    z=i*i+j*j;
                    //printf("%d %d %d\n",x,y,z);
                    ans++;
                }
                for(int tt=1;;tt++)
                {
                    if(tt*z>n)
                        break;
                    tag[x*tt]=1;
                    tag[y*tt]=1;
                    tag[z*tt]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(tag[i]==0)
            total++;
    printf("%d %d\n",ans,total);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        solve();
    }
    return 0;
}
