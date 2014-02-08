/*
    状态dp     --by qqspeed
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[1<<16];
int n;
int map[17][17];
int num1[17],num2[17],num3[17],num4[17];
inline int getone(int i)
{
    int cnt=0;
    while(i) cnt+=i%2,i>>=1;
    return cnt;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(num1,0,sizeof(num1));
        memset(num3,0,sizeof(num3));
        memset(num4,0,sizeof(num4));
        memset(num2,0,sizeof(num2));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&map[i][j]);
            }
        int tag=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j)
                {
                    if(map[i][j]&&map[j][i]) tag=0;break;
                }
        if(!tag)
        {
            puts("0");
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(map[j][i]) num1[i]++;
                if(map[i][j]) num2[i]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(map[j][i]) num3[i]++;
                if(map[i][j]) num4[i]++;
            }
        }
        int all=(1<<n)-1;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=all;i++)
        {
            int rr=getone(i)-1;
            ll ans=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    int l=0,r=0,ll=0,rrr=0;
                    for(int k=0;k<j;k++)
                        (i&(1<<k))?l++:ll++;
                    for(int k=j+1;k<n;k++)
                        (i&(1<<k))?r++:rrr++;
                    if(r<num1[rr]) continue;
                    if(l<num2[rr]) continue;
                    if(rrr<num3[rr]) continue;
                    if(ll<num4[rr]) continue;
                    ans+=dp[i&(~(1<<j))];
                }
            }
            dp[i]=ans;
        }
        printf("%lld\n",dp[all]);
    }
    return 0;
}
