/*
    math
���ڸ�����g��l��l�϶���g�ı����������޽⣬
���֮������ʽ�ֽ⣬������ǽ����������ӷ��䣬���Եõ�����������
��ô����������һ��������⡣
����������һ��������p������Ϊx��x>=1����
���������ֵ��������һ���ֵ�����Ϊ0��������һ���ֵ�����Ϊx�����Է�����Ϊ
 1.�����һ���ݴ���0С��x������������ 6*��x-1��
 2.�������Ϊx ������������3��
 3.�������Ϊ0������������3��
�ܵľ���6x�֡�Ȼ��������������ӵ��������һ���۳ˡ�����

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
