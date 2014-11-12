#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
long long num[101];
long long a,b;
void solve()
{
    memset(num,0,sizeof(num));
    long long p=2;
    b++;
    for(int i=1;i<=30;i++)
    {
        num[i]+=b/p*(p/2);
        int remain=b%p;
        if(remain<=p/2)
            ;
        else
            num[i]+=remain-p/2;
        p*=2;
    }
    p=2;
    for(int i=1;i<=30;i++)
    {
        num[i]-=a/p*(p/2);
        int remain=a%p;
        if(remain<=p/2)
            ;
        else
            num[i]-=remain-p/2;
        p*=2;
    }
    long long sy=0;
    for(int i=1;i<=100;i++)
    {
        sy+=num[i]/2;
        num[i+1]+=num[i]/2;
    }
    printf("%lld\n",sy);
    return ;
}
int main()
{
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        solve();
    }
    return 0;
}
