#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
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
            E.m[i][j]=(i==j);
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
Matrix Pow(Matrix A,long long k)
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
int main()
{
    init();
    long long k,l;
    while(scanf("%lld%lld",&k,&l)!=EOF)
    {
        mod=k;
        Matrix ans;
        ans.m[1][1]=l%mod;
        ans.m[1][2]=l*(l-1)%mod;
        ans.m[2][1]=1;
        ans.m[2][2]=l%mod;
        ans=Pow(ans,k);
        printf("%lld\n",(ans.m[1][1]*2+mod-1)%mod);
    }
    return 0;
}
