/*
dp[i][0] ��������14�����ֹ�2��3
dp[i][1] ĩλΪ1������������14�����ֹ�2��3
dp[i][2] ĩλΪ1������������14��û���ֹ�2��3 // �����ʵһֱ������1
dp[i][3] ĩλΪ4������������14��û���ֹ�2��3 // ���Ҳ��
dp[i][4] ĩλΪ4������������14�����ֹ�2��3
dp[i][5] ��������14��û���ֹ�2��3
dp[i][6] ĩλΪ2��3��û���ֹ�������14
then��
dp[i][0]=4*dp[i-1][0]+dp[i-1][1]+dp[i-1][4]+2*dp[i-1][5];
dp[i][1]=dp[i-1][4]+dp[i-1][6];
dp[i][2]=dp[i-1][2];
dp[i][3]=dp[i-1][3];
dp[i][4]=dp[i-1][1]+dp[i-1][6];
dp[i][5]=dp[i-1][2]+dp[i-1][3]+2*dp[i-1][5];
dp[i][6]=2*(dp[i-1][2]+dp[i-1][3]+dp[i-1][1]+dp[i-1][4]+dp[i-1][6]);
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
unsigned long long dp[32][7];
int main()
{
    dp[2][0]=0;
    dp[2][1]=2;
    dp[2][2]=1;
    dp[2][3]=1;
    dp[2][4]=2;
    dp[2][5]=2;
    dp[2][6]=8;
    for(int i=3;i<=32;i++)
    {
        dp[i][0]=4*dp[i-1][0]+dp[i-1][1]+dp[i-1][4]+2*dp[i-1][5];
        dp[i][1]=dp[i-1][4]+dp[i-1][6];
        dp[i][2]=dp[i-1][2];
        dp[i][3]=dp[i-1][3];
        dp[i][4]=dp[i-1][1]+dp[i-1][6];
        dp[i][5]=dp[i-1][2]+dp[i-1][3]+2*dp[i-1][5];
        dp[i][6]=2*(dp[i-1][2]+dp[i-1][3]+dp[i-1][1]+dp[i-1][4]+dp[i-1][6]);
    }
    for(int i=2;i<=31;i++)
        printf("N=%d: %I64u\n",i,dp[i][0]);
    return 0;
}
