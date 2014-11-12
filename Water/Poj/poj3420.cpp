#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,mod;
struct Matrix
{
    int m[17][17];
}E,D;
void init()
{
    for(int i=1;i<=16;i++)
        for(int j=1;j<=16;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
        }

    D.m[1][1]=1;
    D.m[1][4]=1;
    D.m[1][10]=1;
    D.m[1][13]=1;
    D.m[1][16]=1;

    D.m[2][3]=1;
    D.m[2][9]=1;
    D.m[2][15]=1;

    D.m[3][2]=1;
    D.m[3][14]=1;

    D.m[4][1]=1;
    D.m[4][13]=1;

    D.m[5][9]=1;
    D.m[5][12]=1;

    D.m[6][11]=1;

    D.m[7][10]=1;

    D.m[8][9]=1;

    D.m[9][2]=1;
    D.m[9][5]=1;
    D.m[9][8]=1;

    D.m[10][1]=1;
    D.m[10][7]=1;

    D.m[11][6]=1;

    D.m[12][5]=1;

    D.m[13][1]=1;
    D.m[13][4]=1;

    D.m[14][3]=1;

    D.m[15][2]=1;

    D.m[16][1]=1;
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
Matrix Pow(Matrix A,long long k)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(ans,A,16,16,16);
        }
        else
        {
            k/=2;
            A=Multi(A,A,16,16,16);
        }
    }
    return ans;
}
int main()
{
    init();
    while(scanf("%lld%lld",&n,&mod)!=EOF)
    {
        if(n+mod==0)
            break;
        Matrix tmp;
        tmp.m[1][1]=1;
        for(int i=2;i<=16;i++)
            tmp.m[i][1]=0;
        Matrix cnt=Pow(D,n);
        cnt=Multi(cnt,tmp,16,16,1);
        printf("%lld\n",cnt.m[1][1]%mod);
    }
    return 0;
}






   0000  --->   0000        0001  --->  1000      0010  --->  0001
                0011                    0010                  1101
                1100                    1110
                1111                              1111  --->  0000
                1001

   0011  --->   0000        0100  --->  1000      0101  --->  1010
                1100                    1011


   0110  --->   1001        0111  --->  1000      1000  --->  0001
                                                              0100
                                                              0111

   1001  --->   0000        1010  --->  0101      1011  --->  0100
                0110

   1100  --->   0000        1101  --->  0010      1110  --->  0001
                0011
