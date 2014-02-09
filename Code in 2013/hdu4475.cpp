/*
    对于每一个到达当前行i的情况存在a（i）种
    对于下一个i+1分别存在（i+1）个左斜杠和右斜杠
    所以存在的情况就是 2 * （i+1）* a（i）
    当n>=mod时，值为0
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define mod 1000003
__int64 ans[mod+1];
int main()
{
    ans[0]=1;
    for(int i=1;i<=mod;i++)
        ans[i]=(ans[i-1]*i*2)%mod;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        __int64 n;
        scanf("%I64d",&n);
        if(n>=mod)
            printf("0\n");
        else
            printf("%I64d\n",ans[n]);
    }
    return 0;
}
