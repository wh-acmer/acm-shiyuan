#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        if(n&1)
            printf("ailyanlu\n");
        else
            printf("8600\n");
    }
    return 0;
}

/*
     water
 思路：和喵呜昨天讲的一样（圆桌上放硬币的）
 同理，如果n是奇数，先手可以放中心，剩下的跟对手一样对称
 如果n是偶数，那么后手一定可以有位置取
 */
