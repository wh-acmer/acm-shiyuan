/*
    matrix
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int mod=8191;
struct Matrix
{
    int m[3][3];
};
Matrix B,E,D;
void Init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
}
void make(int x,int y,int d)
{
    B.m[1][1]=B.m[2][2]=x;
    B.m[2][1]=y;
    B.m[1][2]=d*y;
    D.m[1][1]=x;
    D.m[2][1]=y;
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
            ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
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
int find(int k)
{
    int y=1;
    int x;
    while(1)
    {
        x=(long long)sqrt(k*y*y+1);
        if(x*x==k*y*y+1)
            break;
        y++;
    }
    return x;
}
int main()
{
    int N,K;
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        int tt=sqrt(N*1.0);
        if(tt*tt==N)
        {
            printf("No answers can meet such conditions\n");
        }
        else
        {
            int x1=find(N);
            Init();
            int y1=x1*x1-1;
            y1/=N;
            y1=sqrt(y1);
            make(x1,y1,N);
            Matrix ans=Pow(B,K-1);
            int aa=(ans.m[1][1]*D.m[1][1])%mod;
            aa=(aa+(ans.m[1][2]*D.m[2][1])%mod)%mod;
            printf("%d\n",aa);
        }
    }
    return 0;
}
