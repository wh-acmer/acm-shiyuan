#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const long long mod = ((long long)1<<32);
struct Matrix
{
    long long m[55][55];
}E,D;
long long n,k;
long long fac[51][51];
void init()
{
    for(int i=1;i<=54;i++)
        for(int j=1;j<=54;j++)
            E.m[i][j]=(i==j);

    for(int i=0;i<=50;i++)
    {
        fac[i][0]=1;
        fac[i][i]=1;
        fac[i][1]=i;
    }
    for(int i=2;i<=50;i++)
        for(int j=1;j<=i;j++)
            fac[i][j]=(fac[i-1][j]+fac[i-1][j-1])%mod;

}
long long Pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            b--;
            ans=(ans*a)%mod;
        }
        else
        {
            b/=2;
            a*=a;
            a%=mod;
        }
    }
    return ans;
}
void make()
{
    for(int i=1;i<=k+2;i++)
        for(int j=1;j<=k+2;j++)
            D.m[i][j]=0;

    D.m[1][1]=1;
    for(int i=2;i<=k+2;i++)
        D.m[1][i]=fac[k][i-2];
    for(int i=2;i<=k+2;i++)
    {
        for(int j=i;j<=k+2;j++)
            D.m[i][j]=fac[k+2-i][j-i];
    }
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
Matrix Pow(Matrix A,long long e)
{
    Matrix ans=E;
    while(e)
    {
        if(e&1)
        {
            e--;
            ans=Multi(ans,A,k+2,k+2,k+2);
        }
        else
        {
            e/=2;
            A=Multi(A,A,k+2,k+2,k+2);
        }
    }
    return ans;
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%lld%lld",&n,&k);
        make();
        printf("Case %d: ",cases);
        Matrix tmp;
        for(int i=1;i<=k+2;i++)
            tmp.m[i][1]=1;
        Matrix cnt=Pow(D,n-1);
        Matrix ans=Multi(cnt,tmp,k+2,k+2,1);
        printf("%lld\n",ans.m[1][1]%mod);
    }
    return 0;
}

/*

令函数表示f(x)=1^k+2^k+3^k+....+x^k

f(x+1)=f(x)+(x+1)^k
      =f(x)+C(k,0)*x^k+C(k,1)*x^(k-1)+C(k,2)*x^(k-2)+...+C(k,k-1)*x+1

so 构造矩阵

当前矩阵            目标矩阵：
    |  f(x)   |         |    f(x+1)    |
    |  x^k    |         |   (x+1)^k    |
    | x^(k-1) |         |  (x+1)^(k-1) |
    | x^(k-2) |         |  (x+1)^(k-2) |
    | x^(k-3) |         |  (x+1)^(k-3) |
    | ....... |         |    .......   |
    |  x^1    |         |     x+1      |
    |   1     |         |      1       |

所以操作矩阵 D :
    | 1  C(k,0)  C(k,1)   C(k,2)  ...     C(k,k)   |
    | 0  C(k,0)  C(k,1)   C(k,2)  ...     C(k,k)   |
    | 0    0    C(k-1,0) C(k-1,1)  ...  C(k-1,k-1) |
    | 0    0       0     C(k-2,0)  ...  C(k-2,k-2) |
    |  ...   ...  ...    ...  ...   ...   ...  ..  |
    | 0    0       0        0 ... C(1,0)  C(1,1)   |
    | 0    0       0        0   ...  0       1     |


*/
