#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
long long n;
long long get_5(long long n)
{
    long long ans=0;
    long long five=5;
    while(n>=five)
    {
        ans+=n/five;
        five*=5;
    }
    return ans;
}
long long solve(long long l,long long r)
{
    long long mid=(l+r)/2;
    long long tmp=get_5(mid);
    if(l==r)
    {
        if(get_5(mid)==n)
            return mid;
        else
            return -1;
    }
    if(tmp<n)
    {
        return solve(mid+1,r);
    }
    else if(tmp>n)
    {
        return solve(l,mid);
    }
    else
        return mid;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%lld",&n);
        long long ans=solve(0,1000000000000);
        if(ans==-1)
            printf("Case %d: impossible\n",cases);
        else
        {
            while(get_5(ans-1)==n)
                ans--;
            printf("Case %d: %lld\n",cases,ans);
        }
    }
    return 0;
}
