#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int mod=10000;
struct Matrix
{
    long long m[3][3];
}E,D;
void init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=1;
        }
    D.m[2][2]=0;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=2;k++)
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
        }
    return ans;
}
Matrix Pow(Matrix A,long long k)
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
    init();
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==-1)
            break;
        Matrix ans=Pow(D,n);
        printf("%lld\n",ans.m[2][1]);
    }
    return 0;
}
