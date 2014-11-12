#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct Matrix
{
    long long m[101][101];
}E;
long long mod;
int n;
long long a[101];
void init()
{
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            E.m[i][j]=(i==j);
}
Matrix MULTI(Matrix A,Matrix B)
{
    Matrix ans;
    int i=1;
    for(int j=1;j<=n;j++)
    {
        ans.m[i][j]=0;
        for(int k=1;k<=n;k++)
           ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
    }
    for(i=2;i<=n;i++)
    {
        ans.m[i][1]=ans.m[i-1][n];
        for(int j=2;j<=n;j++)
            ans.m[i][j]=ans.m[i-1][j-1];
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
            ans=MULTI(ans,A);
        }
        else
        {
            k/=2;
            A=MULTI(A,A);
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    init();
    while(t--)
    {
        int round;
        int R,L;
        scanf("%d%d%d%d%lld",&n,&round,&R,&L,&mod);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        Matrix ans=E;
        for(int i=1;i<n;i++)
        {
            ans.m[i][i+1]=L;
            ans.m[i+1][i]=R;
        }
        ans.m[n][1]=L;
        ans.m[1][n]=R;
        ans=Pow(ans,round);

        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%lld ",ans.m[i][j]);
            printf("\n");
        }*/

        for(int i=1;i<=n;i++)
        {
            long long sum=0;
            if(i!=1)
                printf(" ");
            for(int j=1;j<=n;j++)
                sum=(sum+ans.m[j][i]*a[j])%mod;
            printf("%lld",sum%mod);
        }
        printf("\n");
    }
    return 0;
}
