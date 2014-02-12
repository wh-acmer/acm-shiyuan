/*
    Ã¶¾Ù
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;
#define maxn 100010
double inf = 1e20;
double p[maxn][5];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            scanf("%lf", &p[i][j]);
    }
    double ans = 0;
    for (int i = 0; i < (1 << 5); i++)
    {
        double mi = inf, mx = -inf;
        for (int j = 0; j < n; j++)
        {
            double tmp = 0;
            for (int k = 0; k < 5; k++)
            {
                if (i&(1 << k))
                    tmp += p[j][k];
                else
                    tmp -= p[j][k];
            }
            mx = max(mx, tmp);
            mi = min(mi, tmp);
        }
        ans = max(mx - mi, ans);
    }
    printf("%.2lf\n", ans);
    //system("pause");
    return 0;
}
