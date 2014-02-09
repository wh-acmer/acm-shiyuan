/*
    matrix
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
__int64 mod;
struct Matrix
{
    __int64 m[53][53];
}E,D,Miao;
__int64 c[53][53];
void init_Matrix()
{
    for(int i=1;i<=52;i++)
        for(int j=1;j<=52;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
        }
}
Matrix Multi(Matrix A,Matrix B,int m,int n,int k)
{
    Matrix ans;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=k;j++)
        {
            ans.m[i][j]=0;
            for(int l=1;l<=n;l++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][l]*B.m[l][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,__int64 k,__int64 m)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(ans,A,m,m,m);
        }
        else
        {
            k/=2;
            A=Multi(A,A,m,m,m);
        }
    }
    return ans;
}
void init_C(__int64 x)
{
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for(int i=1;i<=50;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
}
void make(__int64 x)
{
    D.m[1][1]=1;
    for(int i=2;i<=x+2;i++)
        D.m[1][i]=(x*c[x][i-2])%mod;
    for(int i=2;i<=x+2;i++)
        for(int j=i;j<=x+2;j++)
            D.m[i][j]=(x*c[x+2-i][j-i])%mod;
    for(int i=1;i<=x+2;i++)
        Miao.m[i][1]=x%mod;
}
int main()
{
    __int64 n,x;
    init_Matrix();
    while(scanf("%I64d%I64d%I64d",&n,&x,&mod)!=EOF)
    {
        if(n<0&&x<0&&mod<0)
            break;
        init_C(x);
        make(x);
        D=Pow(D,n-1,x+2);
        Matrix ans=Multi(D,Miao,x+2,x+2,1);
        printf("%I64d\n",ans.m[1][1]);
    }
    return 0;
}
