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
char s[25][25];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x,int y)
{
    if(s[x][y]=='#')
        return ;
    s[x][y]='@';
    int xx,yy;
    for(int i=0;i<4;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx>=0&&xx<m&&yy>=0&&yy<n&&s[xx][yy]=='.')
            dfs(xx,yy);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=0;i<m;i++)
            scanf("%s",&s[i]);
        int x,y;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(s[i][j]=='@')
                {
                    x=i;
                    y=j;
                    break;
                }
        dfs(x,y);
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(s[i][j]=='@')
                    ans++;
        printf("%d\n",ans);
    }
    return 0;
}
