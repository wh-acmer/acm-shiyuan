/*
    ����ÿһ�����ﵱǰ��i���������a��i����
    ������һ��i+1�ֱ���ڣ�i+1������б�ܺ���б��
    ���Դ��ڵ�������� 2 * ��i+1��* a��i��
    ��n>=modʱ��ֵΪ0
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
