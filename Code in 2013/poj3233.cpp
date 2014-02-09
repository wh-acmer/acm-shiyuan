/*
    matrix water
*/
#include <cstdio>
#include <iostream>
using namespace std;
struct Matrix
{
    int m[31][31];
};
Matrix A,B,E;
int mod,n,k;
Matrix multi(Matrix A,Matrix B)
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
Matrix Pow(Matrix A,int e)
{
    Matrix ans=E;
    while(e)
    {
        if(e&1)
            ans=multi(A,ans);
        A=multi(A,A);
        e/=2;
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
Matrix Sum(Matrix A,int e)
{
    if(e==1)
        return A;
    Matrix tmp=E;
    tmp=Add(tmp,Pow(A,e/2));
    tmp=multi(tmp,Sum(A,e/2));
    if(e&1)
        tmp=Add(tmp,Pow(A,e));
    return tmp;
}
int main()
{
    scanf("%d%d%d",&n,&k,&mod);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&A.m[i][j]);
            E.m[i][j]=(i==j);
            B.m[i][j]=0;
        }
    A=Sum(A,k);
    for(int i=1;i<=n;i++)
    {
        printf("%d",A.m[i][1]);
        for(int j=2;j<=n;j++)
            printf(" %d",A.m[i][j]);
        printf("\n");
    }
    return 0;
}
