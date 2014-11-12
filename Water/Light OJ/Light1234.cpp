#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 1000010
#define gamma 0.57721566490153286060651209008240243104215933593992
double sum[maxn];
void init()
{
    sum[0]=0;
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+1.0/i;
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: ",cases);
        if(n<maxn)
            printf("%.8lf\n",sum[n]);
        else
            printf("%.8lf\n",(log(n)+log(n+1))/2+gamma);
    }
    return 0;
}
