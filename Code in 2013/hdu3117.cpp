/*
    water
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int f[21];
int a[15001];
int main()
{
    int n;
    f[0]=0,f[1]=1;
    a[0]=0,a[1]=1;
    for(int i=2;i<=15001;i++)
        a[i]=(a[i-1]+a[i-2])%10000;
    for(int i=2;i<=40;i++)
        f[i]=f[i-1]+f[i-2];
    while(scanf("%d",&n)!=EOF)
    {
        if(n<40)
        {
            printf("%d\n",f[n]);
        }
        else
        {
            double ans= -0.5*log(5.0)/log(10.0)+((double)n)*log((sqrt(5.0)+1)/2.0)/log(10.0);
            ans=ans-(floor)(ans);
            ans=pow(10.0,ans);
            while(ans<1000)
                ans*=10;
            printf("%d...%04d\n",(int)ans,a[(int)n%15000]);
        }
    }
    return 0;
}
