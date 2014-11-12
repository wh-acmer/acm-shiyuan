#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct Matrix
{
    long long m[3][3];
};
Matrix E,D;
long long x,y;
void init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
    D.m[1][1]=x;
    D.m[2][1]=2;
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
int main()
{
    long long n;
    while(cin>>x>>y>>n)
    {
        if(n==0)
        {
            printf("2\n");
            continue;
        }
        init();
        Matrix ans;
        ans.m[1][1]=x;
        ans.m[1][2]=-y;
        ans.m[2][1]=1;
        ans.m[2][2]=0;
        ans=Pow(ans,n-1);
        Matrix tmp;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=1;j++)
            {
                tmp.m[i][j]=0;
                for(int k=1;k<=2;k++)
                    tmp.m[i][j]+=ans.m[i][k]*D.m[k][j];
            }
        printf("%lld\n",tmp.m[1][1]);
    }
    return 0;
}
/*
已知：
    x=a+b
    y=a*b
求:
    a^n+b^n

构造矩阵
    X(n)=a^n+b^n
    ...
    X(0)=2;
    X(1)=a+b=x;

X(n)=(a+b)*X(n-1) - a*b*X(n-2)

| (a+b) -a*b |     | X(n-1)|    |  X(n)  |
|            |  *  |       |  = |        |
|   1     0  |     | X(n-2)|    | X(n-1) |

*/
