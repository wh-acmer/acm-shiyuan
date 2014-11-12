// http://coder.buct.edu.cn/JudgeOnline/problem.php?cid=1021&pid=2
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int prime[1000010];
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    long long m,k;
    while(scanf("%lld%lld",&m,&k)!=EOF)
    {
        int n=0;
        for(int i=1;i<=m;i++)
            if(gcd(m,i)==1)
                prime[++n]=i;
        long long ans;
        if(k%n==0)
            ans=m*(k/n-1)+prime[n];
        else
            ans=m*(k/n)+prime[k%n];
        printf("%lld\n",ans);
    }
    return 0;
}
