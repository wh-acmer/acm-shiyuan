/*
    math
对于给定的g和l，l肯定是g的倍数，否则无解，
相除之后，质因式分解，如果我们将所有质因子分配，可以得到那三个数，
那么接下来就是一个组合问题。
对于其任意一个质因子p，其幂为x（x>=1），
分配的三个值，至少有一个分到的幂为0，至少有一个分到的幂为x，所以方案数为
 1.分配的一个幂大于0小于x的算上排列数 6*（x-1）
 2.分配的幂为x 算上排列数有3种
 3.分配的幂为0算上排列数有3种
总的就是6x种。然后对其所有质因子的情况进行一个累乘。。。

*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define maxn 66000
bool vis[maxn];
vector<int>v;
int cnt[7000];
void init()
{
    v.clear();
    memset(vis, true, sizeof(vis));
    vis[0] = vis[1] = 0;
    for (int i = 2; i < maxn;i++)
        if (vis[i])
        {
            v.push_back(i);
            for (int j = 2 * i; j < maxn; j += i)
                vis[j] = 0;
        }
}
int main()
{
    init();
    //cout << v.size() << endl;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        LL r, l;
        scanf("%I64d%I64d", &r, &l);
        if (l%r != 0)
        {
            printf("0\n");
            continue;
        }

        LL tmp = l / r;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < v.size(); i++)
        {
            if (tmp < v[i])
                break;
            if (tmp%v[i] == 0)
            {
                while (tmp%v[i] == 0)
                {
                    tmp /= v[i];
                    cnt[i]++;
                }
            }
        }
        LL ans = 1;
        if (tmp != 1)
            ans *= 6;
        for (int i = 0; i < 7000; i++)
            if (cnt[i])
                ans *= 6 * cnt[i];
        printf("%I64d\n", ans);
    }
    //system("pause");
    return 0;
}
