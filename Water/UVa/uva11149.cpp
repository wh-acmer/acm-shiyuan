#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct Matrix
{
    int m[41][41];
};
Matrix E;
int n;
void init()
{
    for(int i=1;i<=41;i++)
        for(int j=1;j<=41;j++)
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
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%10;
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
Matrix Add(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans.m[i][j]=(A.m[i][j]+B.m[i][j])%10;
    return ans;
}
Matrix Sum(Matrix A,int k)
{
    if(k==0)
        return E;
    if(k==1)
        return A;
    Matrix ans=Sum(A,k/2);
    Matrix cnt=Add(E,Pow(A,k/2));
    ans=Multi(ans,cnt);
    if(k&1)
        ans=Add(ans,Pow(A,k));
    return ans;
}
int main()
{
    int k;
    init();
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(n==0)
            break;
        Matrix D;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&D.m[i][j]);
                D.m[i][j]%=10;
            }
        Matrix ans=Sum(D,k);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++)
                printf("%d ",ans.m[i][j]);
            printf("%d\n",ans.m[i][n]);
        }
        printf("\n");
    }
    return 0;
}
