/*
    water
*/
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v[6];
int n;
int m;
int vis[10][10];
int fun(int x,vector<int>vv)
{
    int cnt=vv.size()/4;
    int ans=0;
    for(int i=0;i<4;i++)
    {
        int tmp=i*cnt+x;
        ans+=vv[tmp];
    }
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&vis[i][j]);
        m=(n+1)/2;
        int x=1,y=1;
        int row=n,col=n;
        for(int i=1;i<=m;i++)
        {
            v[i].clear();
            while(y>=1&&y<=col+1-i)
            {
                v[i].push_back(vis[x][y]);
                y++;
            }
            y--;
            x++;
            while(x>=1&&x<=row+1-i)
            {
                v[i].push_back(vis[x][y]);
                x++;
            }
            x--;
            y--;
            while(y>=i)
            {
                v[i].push_back(vis[x][y]);
                y--;
            }
            y++;
            x--;
            while(x>i)
            {
                v[i].push_back(vis[x][y]);
                x--;
            }
            x++,y++;
        }
        int answer=0,step=0;
        answer+=vis[m][m];
        for(int i=1;i<=m;i++)
        {
            int cnt=v[i].size()/4; // 最大旋转次数
            int ans=0,miao=0;
            for(int j=0;j<cnt;j++)
            {
                int tmp=fun(j,v[i]);
                if(tmp==ans) // 擦。。这里Wa了好多次
                {
                    ans=tmp;
                    miao=min(miao,min(cnt-j,j));
                }
                if(tmp>ans)
                {
                    ans=tmp;
                    miao=min(cnt-j,j);
                }
            }
            answer+=ans;
            step+=miao;
        }
        printf("%d %d\n",answer,step);
    }
    return 0;
}
