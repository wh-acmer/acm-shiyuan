/*
    dfs
*/
#include <stdio.h>
int dp[101][101];
int move[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,k,map[101][101];
int dfs(int x,int y)
{
    int i,j,xx,yy,temp,m=0;
    if(dp[x][y]!=0)
    return dp[x][y];
    for(i=0;i<4;i++)
    for(j=1;j<=k;j++)//开始的时候一直忽略了k
    {
        xx=x+move[i][0]*j;
        yy=y+move[i][1]*j;
        if(xx<=n&&xx>=1&&yy>=1&&yy<=n&&map[xx][yy]>map[x][y]) //控制边界范围内，且下一个值较大
        {
            temp=dfs(xx,yy);
            if(m<temp)
            m=temp;
        }
    }
    dp[x][y]=m+map[x][y];//表示从（x,y）开始到走不动所能吃的cheese加上初始位置的
    return dp[x][y];
}
int main()
{
    while(scanf("%d%d",&n,&k),n!=-1||k!=-1)
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&map[i][j]);
            dp[i][j]=0;
        }
        dfs(1,1);
        printf("%d\n",dp[1][1]);
    }
    return 0;
}
