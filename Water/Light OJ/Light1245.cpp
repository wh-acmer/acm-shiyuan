#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long solve(int n)
{
    long long ans=0;
    for(int i=1;i<=(int)sqrt(n);i++)
    {
        ans+=n/i;
        if(n/i>n/(i+1))
            ans+=(n/i-n/(i+1))*i;
    }
    if(n/((int)sqrt(n))==(int)sqrt(n))
        ans-=(int)sqrt(n);
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %lld\n",cases,solve(n));
    }
    return 0;
}
