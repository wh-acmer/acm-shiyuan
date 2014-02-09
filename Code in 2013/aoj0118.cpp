/*
    dfs
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
int m,n;
char s[110][110];
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};
void dfs(int x,int y,char c)
{
    if(s[x][y]=='.')
        return ;
    s[x][y]='.';
    int xx,yy;
    for(int i=0;i<4;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx>=0&&xx<m&&yy>=0&&yy<n&&s[xx][yy]==c)
        {
            dfs(xx,yy,c);
        }
    }
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0&&n==0)
            break;
        for(int i=0;i<m;i++)
            scanf("%s",&s[i]);
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(s[i][j]!='.')
                {
                    ans++;
                    dfs(i,j,s[i][j]);
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}
