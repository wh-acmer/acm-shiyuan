/*
    matrix

题意： 求（5+2*sqrt(6)）^n 下取整，再对1024取模
思路：用共轭式写就是 （5 + 2*sqrt(6)）^n = a + b*sqrt(6)
                                         （5 - 2*sqrt(6)）^n = a -  b*sqrt(6)
 （5+2*sqrt(6)）^n + （5-2*sqrt(6)）^n = 2 * a   而 （5 - 2*sqrt(6)）^n 随着n增长是越来越小的
所以 （5+2*sqrt(6)）^n = 2 * a - （5 - 2*sqrt(6)）^n  然后在向下取整得到的便是 2*a-1
关于 a 和 b ,我们可以构造矩阵，初始矩阵是  |  5   2  |　为了得到加一次的幂所需要乘的矩阵是：
|  5   2  |
| 12  5  |　所以剩下来的就是矩阵的快速幂了。。。
*/

#include <cstdio>
#include <algorithm>
#include <cmath>
#define mod 1024
using namespace std;
struct Matrix
{
    int m[3][3];
};
Matrix A,E,B;
void Init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
    B.m[1][1]=5;
    B.m[1][2]=2;
    B.m[2][1]=12;
    B.m[2][2]=5;
    A.m[1][1]=5;
    A.m[1][2]=2;
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
Matrix fun(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=1;i++)
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
void solve(int n)
{
    n--;
    Matrix M=Pow(B,n);
    M=fun(A,M);
    printf("%d\n",(2*M.m[1][1]-1)%mod);
}
int main()
{
    Init();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}
