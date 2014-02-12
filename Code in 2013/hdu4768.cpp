/*
    ¶þ·Ö
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 20010
struct node
{
    long long a,b,c;
}p[maxn];
int n;
long long num(node nod,long long mid)
{
    if(nod.c==0)
    {
        if(mid==nod.a)
            return 1;
        return 0;
    }
    long long ans=0;
    mid=mid<nod.b?mid:nod.b;
    if(mid<nod.a)
        return 0;
    ans=(mid-nod.a)/nod.c+1;
    return ans;
}
long long ok(long long mid)
{
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=num(p[i],mid);
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        long long r=((1LL)<<31),l=0,mid,ans=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d%I64d%I64d",&p[i].a,&p[i].b,&p[i].c);
        }
        int cas=100;
        while(cas-- && l<r)
        {
            mid=(l+r)/2;
            if(ok(mid)&1)
            {
                r=mid;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        long long num=0;
        for(int i=1;i<=n;i++)
        {
            if(ans>=p[i].a && ans<=p[i].b )
            {
                if(p[i].c==0 && ans==p[i].a)
                    num++;
                else if(p[i].c!=0)
                    if((ans-p[i].a)%p[i].c==0)
                        num++;
            }
        }
        if((!ok(ans)&1)||ans==-1)
            printf("DC Qiang is unhappy.\n");
        else
            printf("%I64d %I64d\n",ans,num);
    }
    return 0;
}
