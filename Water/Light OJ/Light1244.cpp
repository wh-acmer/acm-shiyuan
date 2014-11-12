#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define mod 10007
struct Matrix
{
    int m[5][5];
}E,D;
void init()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
        }
    D.m[1][1]=1;
    D.m[1][2]=1;
    D.m[1][3]=1;
    D.m[1][4]=1;
    D.m[2][1]=1;
    D.m[3][2]=1;
    D.m[3][4]=1;
    D.m[4][2]=1;
    D.m[4][3]=1;
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
Matrix Pow(Matrix A,int k)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(A,ans);
        }
        else
        {
            k/=2;
            A=Multi(A,A);
        }
    }
    return ans;
}
int solve(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 5;
    Matrix tmp=Pow(D,n-1);
    Matrix cnt;
    cnt.m[1][1]=1;
    cnt.m[2][1]=1;
    cnt.m[3][1]=0;
    cnt.m[4][1]=0;
    Matrix ans;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=1;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=4;k++)
                ans.m[i][j]=(ans.m[i][j]+tmp.m[i][k]*cnt.m[k][j])%mod;
        }
    return ans.m[1][1];
}
int main()
{
    int t;
    scanf("%d",&t);
    init();
    for(int cases=1;cases<=t;cases++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",cases,solve(n));
    }
    return 0;
}

/*


    f(n)=f(n-1)+f(n-2)+p(n-1)+q(n-1)   表示 2*n 全部填满的方案数

    p(n)=f(n-2)+q(n-1)                 表示 2*n 除右上角一格未填

    q(n)=f(n-2)+p(n-1)                 表示 2*n 除右下角一格未填

    那么构造矩阵：

    初始矩阵：             目标矩阵：          操作矩阵:

        |   f(n-1)  |           |   f(n)  |         | 1 1 1 1 |
        |   f(n-2)  |           |  f(n-1) |         | 1 0 0 0 |
        |   p(n-1)  |           |   p(n)  |         | 0 1 0 1 |
        |   q(n-1)  |           |   q(n)  |         | 0 1 1 0 |


*/
