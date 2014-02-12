#include <string.h>
#include <stdio.h>
int dp[210][210];
int main()
{
    int T,n,m;
    int i,j,k,l;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            int num;
            scanf("%d",&num);
            for(k=0;k<=num;k++)
                for(l=0;k+l<=num;l++)
                {
                    if(l==0&&k==0)
                        continue;
                    dp[i+k][j+l]=(dp[i+k][j+l]+dp[i][j])%10000;
                }
        }
        printf("%d\n",dp[n-1][m-1]);
    }
    return 0;
}
