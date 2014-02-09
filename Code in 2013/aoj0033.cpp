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
int ball[11];
bool tag;
void dfs(int l,int r,int now)
{
    if(now==11)
    {
        tag=true;
        return ;
    }
    if(ball[now]<=l && ball[now]<=r)
        return ;
    else if(ball[now]>l)
        dfs(ball[now],r,now+1);
    else if(ball[now]>r)
        dfs(l,ball[now],now+1);
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            tag=false;
            for(int i=1;i<=10;i++)
                scanf("%d",&ball[i]);
            dfs(0,0,1);
            if(tag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
