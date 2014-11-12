#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
struct Matrix
{
    int m[7][7];
}E,D;
long long a1,a2,b1,b2,c1,c2,mod;
long long f1,f2,f0,g0,g1,g2;
void init()
{
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
            E.m[i][j]=(i==j);
}
void make()
{
    memset(D.m,0,sizeof(D.m));
    D.m[1][1]=a1;
    D.m[1][2]=b1;
    D.m[1][6]=c1;
    D.m[2][1]=1;
    D.m[3][2]=1;
    D.m[4][3]=c2;
    D.m[4][4]=a2;
    D.m[4][5]=b2;
    D.m[5][4]=1;
    D.m[6][5]=1;
}
Matrix Multi(Matrix A,Matrix B,int M,int N,int K)
{
    Matrix ans;
    for(int i=1;i<=M;i++)
        for(int j=1;j<=K;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=N;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,int k,int n)
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
int main()
{
    int t;
    scanf("%d",&t);
    init();
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%lld%lld%lld",&a1,&b1,&c1);
        scanf("%lld%lld%lld",&a2,&b2,&c2);
        make();
        scanf("%lld%lld%lld",&f0,&f1,&f2);
        scanf("%lld%lld%lld",&g0,&g1,&g2);
        Matrix ans;
        ans.m[1][1]=f2;
        ans.m[2][1]=f1;
        ans.m[3][1]=f0;
        ans.m[4][1]=g2;
        ans.m[5][1]=g1;
        ans.m[6][1]=g0;
        scanf("%lld",&mod);
        int query;
        scanf("%d",&query);
        printf("Case %d:\n",cases);
        for(int i=1;i<=query;i++)
        {
            int n;
            scanf("%d",&n);
            if(n<3)
            {
                if(n==0)
                    printf("%lld %lld\n",f0%mod,g0%mod);
                else if(n==1)
                    printf("%lld %lld\n",f1%mod,g1%mod);
                else
                    printf("%lld %lld\n",f2%mod,g2%mod);
            }
            else
            {
                Matrix tmp=Pow(D,n-2,6);
                tmp=Multi(tmp,ans,6,6,1);
                printf("%lld %lld\n",tmp.m[1][1]%mod,tmp.m[4][1]%mod);
            }
        }
    }
    return 0;
}
