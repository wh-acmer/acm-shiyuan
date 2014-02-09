/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define mod 10
struct Matrix
{
    int m[31][31];
}E,D;
long long n,k;
void init()
{
    for(int i=1;i<=30;i++)
        for(int j=1;j<=30;j++)
            E.m[i][j]=(i==j);
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=n;k++)
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
Matrix Add(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans.m[i][j]=(A.m[i][j]+B.m[i][j])%mod;
    return ans;
}
Matrix Sum(Matrix A,long long k)
{
    if(k==0)
        return E;
    if(k==1)
        return A;
    if(k&1)
        return Add(Multi(Sum(A,k/2),Add(E,Pow(A,k/2))),Pow(A,k));
    else
        return Multi(Sum(A,k/2),Add(Pow(A,k/2),E));
}
int main()
{
    int t;
    scanf("%d",&t);
    init();
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&D.m[i][j]);
        D=Sum(D,k);
        printf("Case %d:\n",cases);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%d",D.m[i][j]%mod);
            printf("\n");
        }
    }
    return 0;
}
