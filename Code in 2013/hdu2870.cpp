/*
    dp
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1010;
int a[maxn],l[maxn],r[maxn];
int map[maxn][maxn];
char vis[maxn][maxn];
int solution(int col)
{
    l[1]=1;
    for(int i=2;i<=col;i++)
    {
        int tmp=i;
        while(tmp>1&&a[i]<=a[tmp-1])
            tmp=l[tmp-1];
        l[i]=tmp;
    }
    r[col]=col;
    for(int i=col-1;i>=1;i--)
    {
        int tmp=i;
        while(tmp<col&&a[i]<=a[tmp+1])
            tmp=r[tmp+1];
        r[i]=tmp;
    }
    int ans=0;
    for(int i=1;i<=col;i++)
        ans=max(ans,(r[i]-l[i]+1)*a[i]);
    return ans;
}
int solve(int row,int col)
{
    int ans=0;
    for(int i=1;i<=row;i++)
    {
        memset(a,0,sizeof(a));
        for(int k=1;k<=col;k++)
        {
            for(int j=i;j<=row;j++)
            {
                if(map[j][k]==1)
                    a[k]++;
                else
                    break;
            }
        }
        ans=max(ans,solution(col));
    }
    return ans;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int ans=0;
        for(int i=1;i<=m;i++)
            scanf("%s",vis[i]);
        for(int i=1;i<=m;i++)
            for(int j=0;j<n;j++)
                if(vis[i][j]=='x'||vis[i][j]=='b'||vis[i][j]=='c')
                    map[i][j+1]=0;
                else
                    map[i][j+1]=1;
        ans=max(ans,solve(m,n));
        for(int i=1;i<=m;i++)
            for(int j=0;j<n;j++)
                if(vis[i][j]=='y'||vis[i][j]=='a'||vis[i][j]=='c')
                    map[i][j+1]=0;
                else
                    map[i][j+1]=1;
        ans=max(ans,solve(m,n));
        for(int i=1;i<=m;i++)
            for(int j=0;j<n;j++)
                if(vis[i][j]=='w'||vis[i][j]=='a'||vis[i][j]=='b')
                    map[i][j+1]=0;
                else
                    map[i][j+1]=1;
        ans=max(ans,solve(m,n));
        printf("%d\n",ans);
    }
    return 0;
}
