/*
    matrix
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef unsigned long long LL;
const LL mod = 1000000007;
struct Matrix
{
    LL m[6][6];
}E,D;
void init()
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            E.m[i][j] = (i == j);
}
Matrix Multi(Matrix A, Matrix B)
{
    Matrix ans;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 1; k <= 5; k++)
                ans.m[i][j] = (ans.m[i][j] + A.m[i][k] * B.m[k][j])%mod;
        }
        return ans;
}
Matrix Pow(Matrix A, LL k)
{
    Matrix ans = E;
    while (k)
    {
        if (k & 1)
        {
            k--;
            ans = Multi(ans, A);
        }
        else
        {
            k /= 2;
            A = Multi(A, A);
        }
    }
    return ans;
}
Matrix last(Matrix A, Matrix B)
{
    Matrix ans;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 1; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 1; k <= 5; k++)
                ans.m[i][j] = (ans.m[i][j] + A.m[i][k] * B.m[k][j])%mod;
        }
        return ans;
}
int main()
{
    LL n, A0, B0, AX, AY, BX, BY;
    init();
    while (scanf("%I64u", &n) != EOF)
    {
        scanf("%I64u%I64u%I64u", &A0, &AX, &AY);
        A0 %= mod;
        AX %= mod;
        AY %= mod;
        scanf("%I64u%I64u%I64u", &B0, &BX, &BY);
        if (n == 0)
        {
            printf("0\n");
            continue;
        }
        B0 %= mod;
        BX %= mod;
        BY %= mod;
        Matrix tmp;
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++)
                tmp.m[i][j] = 0;
        tmp.m[1][1] = AX;
        tmp.m[1][3] = AY;
        tmp.m[2][2] = BX;
        tmp.m[2][3] = BY;
        tmp.m[3][3] = 1;
        tmp.m[5][1] = tmp.m[4][1] = (AX*BY)%mod;
        tmp.m[5][2] = tmp.m[4][2] = (AY*BX)%mod;
        tmp.m[5][3] = tmp.m[4][3] = (AY*BY)%mod;
        tmp.m[5][5] = tmp.m[4][5] = (AX*BX)%mod;
        tmp.m[5][4] = 0;
        tmp.m[4][4] = 1;
        D.m[1][1] = A0;
        D.m[2][1] = B0;
        D.m[3][1] = 1;
        D.m[4][1] = (A0*B0)%mod;
        D.m[5][1] = (A0*B0)%mod;
        Matrix ans = Pow(tmp, n-1);
        ans = last(ans, D);
        printf("%I64u\n", ans.m[4][1]);
    }
    //system("pause");
    return 0;
}
