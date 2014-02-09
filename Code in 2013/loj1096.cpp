/*
    water
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mod 10007
using namespace std;
struct Matrix
{
    int m[5][5];
}E,D;
int n,a,b,c;
void init()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            E.m[i][j]=(i==j);
}
void make()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            D.m[i][j]=0;
    D.m[1][1]=a;
    D.m[1][3]=b;
    D.m[1][4]=1;
    D.m[2][1]=1;
    D.m[3][2]=1;
    D.m[4][4]=1;
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
    int t;
    scanf("%d",&t);
    init();
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%d%d%d%d",&n,&a,&b,&c);
        make();
        printf("Case %d: ",cases);
        if(n<=2)
        {
            printf("0\n");
        }
        else
        {
            Matrix tmp=Pow(D,n-2);
            Matrix ans,cnt;
            for(int i=1;i<=3;i++)
                cnt.m[i][1]=0;
            cnt.m[4][1]=c;
            for(int i=1;i<=4;i++)
                for(int j=1;j<=1;j++)
                {
                    ans.m[i][j]=0;
                    for(int k=1;k<=4;k++)
                        ans.m[i][j]=(ans.m[i][j]+tmp.m[i][k]*cnt.m[k][j])%mod;
                }
            printf("%d\n",ans.m[1][1]);
        }
    }
    return 0;
}
