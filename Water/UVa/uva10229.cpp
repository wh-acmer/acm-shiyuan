#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct Matrix
{
    long long m[3][3];
}E,D;
long long mod;
void init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=1;
        }
    D.m[2][2]=0;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=2;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,int k)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(ans,A);
        }
        else
        {
            k/=2;
            A=Multi(A,A);
        }
    }
    return ans;
}
long long pp(int a,int b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans*=a;
        }
        else
        {
            b/=2;
            a*=a;
        }
    }
    return ans;
}
int main()
{
    init();
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        mod=pp(2,m);
        Matrix ans=Pow(D,n);
        printf("%lld\n",ans.m[1][2]%mod);
    }
    return 0;
}
