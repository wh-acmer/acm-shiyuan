/*
    game

假设a<=b,如果b%a==0,先手胜，
如果b>2*a,那么先手会有至少两种策略来应对，直到a<b<2*a
这个时候是没有选择的余地的，也就是要模拟一下奇偶，
然后回过头来判断b>2*a时应该选择哪种策略。
事实是，当面临b>2*a的局势时，当前者一定存在减去某一倍数给对手一种必败的局势，
所以递归写一个，满足条件时退出。
*/

#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool win;
void solve(int a,int b)
{
    if(a>b)
        swap(a,b);
    if(b%a==0 || b/a>1)
        return ;
    win=!win;
    b=b%a;
    solve(a,b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a+b)
    {
        win=1;
        solve(a,b);
        if(win)
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
