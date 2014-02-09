/*
    matrix
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef unsigned __int64 LL;
const LL Mod = 1000000007;
const LL mod = Mod - 1;
struct Matrix
{
    LL m[3][3];
}E,D;
void init()
{
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
        {
            E.m[i][j] = (i == j);
            D.m[i][j] = 1;
        }
    D.m[2][2] = 0;
}
Matrix Multi(Matrix A, Matrix B)
{
    Matrix ans;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 1; k <= 2; k++)
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
LL Pow(LL a, LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
        {
            b--;
            ans = (ans*a)%Mod;
        }
        else
        {
            b /= 2;
            a = (a*a)%Mod;
        }
    }
    return ans;
}
LL Fib(LL n)
{
    return Pow(D, n).m[2][1]%mod;
}
LL solve(LL a,LL b,LL n)
{
    if (n == 0)
        return a%Mod;
    if (n == 1)
        return b%Mod;
    return (Pow(a, Fib(n-1))*Pow(b, Fib(n)))%Mod;
}
int main()
{
    LL a, b, n;
    init();
    while (scanf("%I64u%I64u%I64u", &a, &b, &n) != EOF)
    {
        printf("%I64u\n", solve(a, b, n));
    }
    return 0;
}
