/*
    matrix water
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define mod 10007
using namespace std;
struct Matrix
{
    int m[5][5];
};
Matrix B,E,D;
int x,y,n;
void Init()
{
    memset(B.m,0,sizeof(B.m));
    for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++)
        E.m[i][j]=(i==j);
    D.m[1][1]=1;
    D.m[2][1]=D.m[3][1]=1;
    D.m[4][1]=B.m[4][2]=1;
    B.m[1][1]=B.m[1][2]=1;
    B.m[2][2]=((x%mod)*(x%mod))%mod;
    B.m[2][3]=(2*(x%mod)*(y%mod))%mod;
    B.m[2][4]=((y%mod)*(y%mod))%mod;
    B.m[3][2]=x%mod;
    B.m[3][3]=y%mod;
}
Matrix Multi(Matrix A,Matrix B,int M,int N,int K)
{
    Matrix ans;
    for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
    {
        ans.m[i][j]=0;
        for(int k=1;k<=K;k++)
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
            ans=Multi(ans,A,4,4,4);
        }
        else
        {
            k/=2;
            A=Multi(A,A,4,4,4);
        }
    }
    return ans;
}
void solve()
{
    Init();
    Matrix ans=Pow(B,n);
    ans=Multi(ans,D,4,1,4);
    printf("%d\n",ans.m[1][1]%mod);
}
int main()
{
    while(scanf("%d%d%d",&n,&x,&y)!=EOF)
    {
        solve();
    }
    return 0;
}
