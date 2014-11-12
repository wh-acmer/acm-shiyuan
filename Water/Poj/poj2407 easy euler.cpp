#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
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
    while(scanf("%lld",&n)!=EOF,n)
    {
        printf("%lld\n",euler(n));
    }
    return 0;
}
