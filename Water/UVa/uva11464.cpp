#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int cnt[20][20],tmp[20][20];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&cnt[i][j]);
        int ans=0xfffffff;
        /// 枚举第一行的1的位置，从而推出下一行 用二进制表示（最多15位）
        for(int s=0;s<(1<<n);s++)
        {
            memset(tmp,0,sizeof(tmp));
            for(int i=0;i<n;i++)
            {
                if(s&(1<<i))
                    tmp[1][i+1]=1;
            }
            int tag=0;
            for(int i=2;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    int total=0;
                    total+=tmp[i-2][j];
                    total+=tmp[i-1][j-1];
                    total+=tmp[i-1][j+1];
                    tmp[i][j]=total%2;
                    if(tmp[i][j]==0&&cnt[i][j]==1)
                    {
                        tag=1;
                        break;
                    }
                }
                if(tag)
                    break;
            }
            int tnt=0;
            if(tag)
                continue;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(cnt[i][j]==1&&tmp[i][j]==0)
                    {
                        tag=1;
                        break;
                    }
                    else if(cnt[i][j]!=tmp[i][j])
                        tnt++;
                }
            if(tag)
                continue;
            else
                ans=min(ans,tnt);
        }
        printf("Case %d: ",cases);
        if(ans==0xfffffff)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
