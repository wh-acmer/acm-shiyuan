#include <stdio.h>
#include <string.h>
int father[105],v[105];
int map[105][105];
int dp[105];
void show(int n) // 输出该点的父节点
{
    if(n==father[n])
    {
        printf("%d",n);// 起始点
        return ;
    }
    show(father[n]);
    printf("->%d",n);
}
int main()
{
    int T,c=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(map,0,sizeof(map));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            father[i]=1;
        }
        v[n+1]=0;
        int a,b,m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        for(int i=1;i<=n+1;i++)
            for(int j=1;j<i;j++)
            {
                if(map[j][i]&&dp[j]+v[i]>dp[i])
                {
                    dp[i]=dp[j]+v[i];
                    father[i]=j; // 记录节点
                }
            }
        printf("CASE %d#\n",++c);
        printf("points : %d\n",dp[n+1]);
        printf("circuit : ");
        show(father[n+1]);
        printf("->1\n"); //终点
        if(T)
        printf("\n");
    }
    return 0;
}
