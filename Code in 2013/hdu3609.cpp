/*
    math
指数循环节。。注意一下取模值最好先预处理。。。
然后注意一下0^0等于1就行了。。。因此导致的，a=0的时候，k&1时，返回0，k为偶数时返回1
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
using namespace std;
long long euler(long long x)
{
    if (x == 1)
        return 0;
    long long i, res = x;
    for (i = 2; i*i <= x; i++)
        if (x%i == 0)
        {
            res = res / i*(i - 1);
            while (x%i == 0)
                x /= i;
        }
        if (x > 1)
            res = res / x*(x - 1);
        return res;
}
long long Pow(long long a, long long b, long long mod)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            b--;
            ans = (ans*a)%mod;
        }
        else
        {
            b /= 2;
            a = (a*a)%mod;
        }
    }
    return ans;
}
long long a,eul;
vector<long long>v;
long long f(long long k,long long cnt)
{
    long long mod = v[cnt];
    if (k == 0)
        return 1;
    if (k == 1)
        return a%mod;
    if (mod == 1)
        return 0;
    return Pow(a%mod, f(k - 1, cnt+1)+v[cnt+1] , mod);
}
int main()
{
    v.clear();
    v.push_back(100000000);
    long long tmp = euler(v[v.size() - 1]);
    while (v[v.size() - 1] != 1)
    {
        v.push_back(tmp);
        tmp = euler(v[v.size() - 1]);
    }
    v.push_back(0);
    long long k;
    while (scanf("%I64d%I64d", &a, &k) != EOF)
    {
        if (a == 0)
        {
            if (k & 1)
                printf("0\n");
            else
                printf("1\n");
            continue;
        }
        int cnt = 0;
        printf("%I64d\n", f(k, cnt));
    }
    //system("pause");
    return 0;
}
