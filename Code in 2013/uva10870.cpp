/*
    water matrix
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Matrix
{
    long long m[20][20];
}E,D;
long long mod;
void init()
{
    for(int i=1;i<=15;i++)
        for(int j=1;j<=15;j++)
            E.m[i][j]=(i==j);
}
Matrix Multi(Matrix A,Matrix B,long long M,long long N,long long K)
{
    Matrix ans;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=K;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=N;k++)
            {
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
                ans.m[i][j]%=mod;
            }
        }
    return ans;
}
Matrix Pow(Matrix A,long long k,int n)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(ans,A,n,n,n);
        }
        else
        {
            k/=2;
            A=Multi(A,A,n,n,n);
        }
    }
    return ans;
}
long long a[20];
int main()
{
    init();
    long long n,d;
    while(scanf("%lld%lld%lld",&d,&n,&mod)!=EOF)
    {
        if(d==0&&n==0&&mod==0)
            break;
        Matrix ans;
        Matrix tmp;
        for(int i=1;i<=d;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(int i=d;i>=1;i--)
        {
            scanf("%lld",&tmp.m[i][1]);
        }
        if(n<=d)
            printf("%lld\n",((tmp.m[d+1-n][1]%mod)+mod)%mod);
        else
        {
            for(int i=1;i<=d;i++)
                for(int j=1;j<=d;j++)
                    ans.m[i][j]=0;
            for(int i=1;i<=d;i++)
                ans.m[1][i]=a[i];
            for(int i=2;i<=d;i++)
                ans.m[i][i-1]=1;
            ans=Pow(ans,n-d,d);
            tmp=Multi(ans,tmp,d,d,1);
            printf("%lld\n",(tmp.m[1][1]%mod+mod)%mod);
        }
    }
    return 0;
}

/*
a1,a2,a3,a4,....,ad

f1,f2,f3,f4,....,fd


a1,a2,a3   f(d)      f(d+1)
1,0,0      f(d-1)
           f(d-2)
           ..
           f(1)
*/
