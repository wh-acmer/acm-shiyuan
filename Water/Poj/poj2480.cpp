// µÒÀû¿ËÀ×¾í»ý
// sigma(gcd(i,n))=sigma(euler(j)*n/j)
// 1<=i<=n   1<=j<=n&&n%j==0
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
long long euler(long long x)
{
    long long i,res=x;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    if(x>1)
        res=res/x*(x-1);
    return res;
}
int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        long long ans=0;
        for(long long i=1;i<sqrt(n*1.0);i++)
            if(n%i==0)
                ans+=(euler(i)*n/i+euler(n/i)*i);
        long long cnt=sqrt(n*1.0);
        if(cnt*cnt==n)
            ans+=euler(cnt)*cnt;
        printf("%lld\n",ans);
    }
    return 0;
}
