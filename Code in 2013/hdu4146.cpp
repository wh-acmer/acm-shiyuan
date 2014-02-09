/*
 water
*/
#include <stdio.h>
#include <string.h>
const int maxn=1001;
int a[maxn][maxn];
char s[maxn][maxn];
int b[maxn],c[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(s[i][j-1]=='w')
                    a[i][j]=1;
            }
        int num;
        scanf("%d",&num);
        while(num--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            b[x]=!b[x];
            c[y]=!c[y];
        }
        for(int i=1;i<=maxn;i++)
        {
            if(b[i])
            {
                for(int j=1;j<=n;j++)
                    a[i][j]=!a[i][j];
            }
            if(c[i])
            {
                for(int j=1;j<=n;j++)
                    a[j][i]=!a[j][i];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(a[i][j])
            ans++;
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
