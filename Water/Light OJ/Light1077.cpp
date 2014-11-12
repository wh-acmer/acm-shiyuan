#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        long long x1,x2,y1,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        printf("Case %d: %lld\n",i,gcd(abs(x1-x2),abs(y1-y2))+1);
    }
    return 0;
}
