/*
    matrix + 循环节

*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
__int64 mod;
struct Matrix
{
    __int64 m[3][3];
}E,D,X;
void init()
{
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            E.m[i][j]=(i==j);
    D.m[1][1]=3;
    D.m[2][1]=1;
    D.m[1][2]=1;
    D.m[2][2]=0;
    X.m[1][1]=1;
    X.m[2][1]=0;
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
Matrix Pow(Matrix A,__int64 k)
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
__int64 solve(__int64 n)
{
    Matrix cnt=Pow(D,n);
    Matrix ans;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=1;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=2;k++)
                ans.m[i][j]=(ans.m[i][j]+cnt.m[i][k]*X.m[k][j])%mod;
        }
    return ans.m[2][1];
}
__int64 answer(__int64 n)
{
    mod=183120;
    __int64 ans=solve(n);
    mod=222222224;
    ans=solve(ans);
    mod=1e9+7;
    return solve(ans);
}
int main()
{
    __int64 n;
    init();
    while(scanf("%I64d",&n)!=EOF)
    {
        printf("%I64d\n",answer(n));
    }
    return 0;
}

// 找循环节
/*  183120  222222224
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long solve(long long mod)
{
    long long x,y,z;
    x=0;
    y=1;
    z=y;
    y=(3*y+x)%mod;
    x=z;
    long long ans=1;
    while(x!=0||y!=1)
    {
        ans++;
        z=y;
        y=(3*y+x)%mod;
        x=z;
    }
    return ans;
}
int main()
{
    printf("%lld\n",solve(solve(1e9+7)));
    return 0;
}
*/
