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
#include <vector>
using namespace std;
int row,col;
int map[21][21];
int sx,sy,gx,gy;
int ans;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y,int now)
{
    if(now>10)
        return ;
    if(x==gx&&y==gy)
    {
        ans=min(ans,now);
        return ;
    }
    for(int i=0;i<4;i++)
    {
       int xx=x+dx[i];
       int yy=y+dy[i];
       if(xx<1||xx>row||yy<1||yy>col||map[xx][yy]==1)
           continue;
       if(xx==gx && yy==gy)
       {
           dfs(xx,yy,now+1);
           continue;
       }
       bool ok1=false,ok2=false;
       while(map[xx][yy]==0)
       {
           xx+=dx[i];
           yy+=dy[i];
           if(xx<1||xx>row||yy<1||yy>col)
           {
               //跑出边界
               ok1=true;
               break;
           }
           if(xx==gx && yy==gy)
           {
               dfs(xx,yy,now+1);
               ok2=true;
           }
       }
       if(ok1||ok2)
          continue;
       //不然就是遇到障碍物的
       map[xx][yy]=0;
       dfs(xx-dx[i],yy-dy[i],now+1);
       map[xx][yy]=1;

    }
}
int main()
{
    while(scanf("%d%d",&col,&row)!=EOF)
    {
        if(row==0&&col==0)
            break;
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]==2)
                {
                    sx=i;
                    sy=j;
                    map[i][j]=0;//可能会反复经过这个点
                }
                else if(map[i][j]==3)
                {
                    gx=i;
                    gy=j;
                }
            }
        ans=11;
        dfs(sx,sy,0);
        if(ans==11)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
