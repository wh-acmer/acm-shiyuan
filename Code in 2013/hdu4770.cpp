/*
    ×´Ì¬Ã¶¾Ù
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef pair<int,int> P;
map<P,int>mp;
vector<P>v;
#define maxn 210
char s[maxn][maxn];
bool vis[20];
int row,col,cnt,tmp;
bool solution;
int dir[5][2]={{0,1},{1,0},{0,-1},{-1,0},{0,1}};
bool can;
bool is(int x,int y)
{
    if(x>=1 && x<=row && y>=1 && y<=col && s[x][y]=='#')
        return false;
    return true;
}
bool in(int x,int y)
{
    if(x>=1 && x<=row && y>=1 && y<=col && s[x][y]=='.')
        return true;
    return false;
}
void solve(int n)
{
    for(int i=0;i<cnt;i++)
    {
        if(i==n || vis[i]==0)
            continue;
        int x,y;
        x=v[i].first;
        y=v[i].second;
        if(is(x-1,y) && is(x,y+1))
        {
            if(in(x-1,y))
                mp[P(x-1,y)]++;
            if(in(x,y+1))
                mp[P(x,y+1)]++;
            mp[P(x,y)]++;
        }
        else
        {
            can=false;
            return ;
        }
    }
    return ;
}
bool ok()
{
    for(int i=0;i<cnt;i++)
    {
        if(vis[i]==0)
            continue;
        for(int j=0;j<4;j++)
        {
            mp.clear();
            int x,y;
            x=v[i].first,y=v[i].second;

            if(is(x+dir[j][0],y+dir[j][1]) && is(x+dir[j+1][0],y+dir[j+1][1]))
            {
                if(in(x+dir[j][0],y+dir[j][1]))
                    mp[P(x+dir[j][0],y+dir[j][1])]++;
                if(in(x+dir[j+1][0],y+dir[j+1][1]))
                    mp[P(x+dir[j+1][0],y+dir[j+1][1])]++;
                mp[P(x,y)]++;
                can=true;
            }
            else
                can=false;
            if(can)
                solve(i);
            if(mp.size()==v.size() && can)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&row,&col)!=EOF)
    {
        if(row+col==0)
            break;
        v.clear();
        for(int i=1;i<=row;i++)
            scanf("%s",s[i]+1);
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                if(s[i][j]=='.')
                    v.push_back(P(i,j));
        if(v.size()==0)
        {
            printf("0\n");
            continue;
        }
        int pika=v.size();
        solution=false;
        for(int i=0;i<(1<<v.size());i++)
        {
            memset(vis,0,sizeof(vis));
            cnt=0;
            int state=i;
            while(state)
            {
                vis[cnt++]=state%2;
                state/=2;
            }
            int num=0;
            for(int j=0;j<cnt;j++)
            {
                if(vis[j])
                    num++;
            }
            if(num>pika)
                continue;
            if(ok())
            {
                pika=min(pika,num);
                solution=true;
            }
        }
        if(solution)
            printf("%d\n",pika);
        else
            printf("-1\n");
    }
    return 0;
}
