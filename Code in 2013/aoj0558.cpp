/*
    bfs
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int>P;
typedef vector<int>VI;
typedef vector<VI>VVI;
typedef vector<string>VS;
typedef map<int,P>MP;
const int maxn = 1010;
VS maze;
int row,col,n;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int bfs(P start,P goal)
{
    int cost=0;
    VVI costs(maze.size(),VI(maze[0].size(),-1));
    costs[start.first][start.second]=0;
    queue<P>q;
    q.push(start);
    while(!q.empty())
    {
        P p=q.front();
        q.pop();
        if(p==goal)
        {
            cost=costs[p.first][p.second];
            break;
        }
        for(int i=0;i<4;i++)
        {
            int x=p.first+dx[i];
            int y=p.second+dy[i];
            if(x>=0&&y>=0&&x<row&&y<col&&maze[x][y]!='X'&&costs[x][y]==-1)
            {
                costs[x][y]=costs[p.first][p.second]+1;
                q.push(P(x,y));
            }
        }
    }
    return cost;
}
int main()
{
    string s;
    cin>>row>>col>>n;
    for(int i=0;i<row;i++)
    {
        cin>>s;
        maze.push_back(s);
    }
    MP mp;
    mp.clear();
    for(int i=0;i<row;i++)
        for(int j=0;j<maze[0].size();j++)
        {
            if(maze[i][j]=='S')
            {
                mp[0]=P(i,j);
            }
            else if(maze[i][j]>='1'&&maze[i][j]<='9')
            {
                mp[maze[i][j]-'0']=P(i,j);
            }
        }
    int ans=0;
    MP::iterator it=mp.begin(),ii=mp.begin();
    ii++;
    for(;ii!=mp.end();it++,ii++)
        ans+=bfs(it->second,ii->second);
    printf("%d\n",ans);
    return 0;
}
