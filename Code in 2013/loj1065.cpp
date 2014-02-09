/*
    water matrix
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
struct Matrix
{
    long long m[3][3];
};
Matrix E,D;
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
            {
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
                ans.m[i][j]%=mod;
            }
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
long long Pow(long long a,long long b)
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
    int t;
    scanf("%d",&t);
    init();
    for(int cases=1;cases<=t;cases++)
    {
        long long a,b,n;
        scanf("%lld%lld%lld%lld",&a,&b,&n,&mod);
        mod=Pow(10,mod);
        Matrix tmp;
        tmp.m[1][1]=b;
        tmp.m[2][1]=a;
        if(n==0)
            printf("Case %d: %lld\n",cases,a%mod);
        else
        {
            Matrix cnt=Pow(D,n-1);
            Matrix ans;
            for(int i=1;i<=2;i++)
            {
                ans.m[i][1]=0;
                for(int k=1;k<=2;k++)
                {
                    ans.m[i][1]+=cnt.m[i][k]*tmp.m[k][1];
                    ans.m[i][1]%mod;
                }
            }
            printf("Case %d: %lld\n",cases,ans.m[1][1]%mod);
        }
    }
    return 0;
}
