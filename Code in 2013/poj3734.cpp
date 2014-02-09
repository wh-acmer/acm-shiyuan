/*
    matrix
*/
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mod 10007
struct Matrix
{
    long long m[5][5];
}E,D,T;
void init()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=1;
        }
    D.m[1][1]=2;
    D.m[1][4]=0;
    D.m[2][2]=2;
    D.m[2][3]=0;
    D.m[3][2]=0;
    D.m[3][3]=2;
    D.m[4][1]=0;
    D.m[4][4]=2;
    T.m[1][1]=2;
    T.m[2][1]=1;
    T.m[3][1]=1;
    T.m[4][1]=0;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=4;k++)
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
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        if(t==0)
            break;
        for(int cas=1;cas<=t;cas++)
        {
            long long n;
            scanf("%I64d",&n);
            Matrix ans;
            ans=Pow(D,n);
            printf("%I64d\n",ans.m[1][1]);
        }
    }
    return 0;
}
