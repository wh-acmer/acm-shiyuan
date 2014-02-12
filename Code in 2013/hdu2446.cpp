/*
    ¶þ·Ö
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define maxn 3812000
unsigned long long fun(unsigned long long x)
{
    return (x*(x+1)*(x+2)/6);
}
unsigned long long ffun(unsigned long long x)
{
    return (x*(x+1))/2;
}
bool ok(unsigned long long mid,unsigned long long n)
{
    if(fun(mid)<n)
        return true;
    return false;
}
bool miao(unsigned long long mid,unsigned long long n)
{
    if(ffun(mid)<n)
        return true;
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long n,l,r,mid,ans;
        scanf("%I64u",&n);
        l=0,r=maxn;
        int cas=200;
        while(cas-- && l<r)
        {
            mid=(l+r)/2;
            if(ok(mid,n))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        n-=fun(ans);
        int pos=ans+1;
        cas=200;
        l=0,r=pos+1;
        while(l<r && cas--)
        {
            mid=(l+r)/2;
            if(miao(mid,n))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        int ppos=ans+1;
        n-=ffun(ans);
        printf("%d %d %I64u\n",pos,ppos,n);
    }
    return 0;
}
