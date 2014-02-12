/*
    euler
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
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
    while(scanf("%I64d",&n)!=EOF)
    {
        long long ans=0;
        long long sq=(long long)sqrt(n);
        for(int i=1;i<=sq;i++)
            if(n%i==0)
            {
                if(i*i==n)
                    ans+=i*euler(i);
                else
                    ans+=n/i*euler(i)+i*euler(n/i);
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
