/*
    matrix + brute force
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct Matrix
{
    double m[101][101];
};
int n;
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=n;k++)
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
        }
    return ans;
}
Matrix Divide(Matrix A,double k)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            A.m[i][j]/=k;
    return A;
}
void Print(Matrix A)
{
    int i,j;
    if(n==1)
        printf("%.2lf \n",A.m[1][1]);
    else
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%.2lf ",A.m[i][j]);
            printf("\n");
        }
    }
}
Matrix Add(Matrix A,Matrix B)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            A.m[i][j]+=B.m[i][j];
    return A;
}
void solve()
{
    Matrix A,ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%lf",&A.m[i][j]);
            ans.m[i][j]=(i==j);
        }
    Matrix B=A;
    for(int i=1;i<=50;i++)
    {
        B=Divide(B,i);
        ans=Add(ans,B);
        B=Multi(B,A);
    }
    Print(ans);
}
int main()
{
    while(scanf("%d",&n),n!=0)
        solve();
    return 0;
}
