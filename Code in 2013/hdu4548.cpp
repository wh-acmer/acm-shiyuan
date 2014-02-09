/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 1000010
bool vis[maxn];
vector<int>v,vv;
bool is_ok(int n)
{
    int nn = n, ans = 0;
    while (nn)
    {
        ans += nn % 10;
        nn /= 10;
    }
    return vis[ans];
}
void init()
{
    memset(vis, true, sizeof(vis));
    vis[0] = vis[1] = 0;
    for (int i = 2; i < maxn;i++)
        if (vis[i])
        {
            vv.push_back(i);
            for (int j = 2 * i; j < maxn; j += i)
                vis[j] = 0;
        }
    for (int i = 0; i < vv.size(); i++)
    {
        if (is_ok(vv[i]))
            v.push_back(vv[i]);
    }
}
int main()
{
    v.clear();
    vv.clear();
    init();
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("Case #%d: %d\n",cas,upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l));
    }
    //system("pause");
    return 0;
}
