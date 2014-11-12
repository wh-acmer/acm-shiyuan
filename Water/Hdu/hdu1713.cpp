#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    long long a,b,c,d;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d/%I64d %I64d/%I64d",&a,&b,&c,&d);
        long long cnt=gcd(a,b);
        a/=cnt;
        b/=cnt;
        long long tmp=gcd(c,d);
        c/=tmp;
        d/=tmp;
        cnt=lcm(a,c);
        b*=cnt/a;
        d*=cnt/c;
        tmp=gcd(b,d);
        if(tmp!=1)
            printf("%I64d/%I64d\n",cnt,tmp);
        else
            printf("%I64d\n",cnt);
    }
    return 0;
}
