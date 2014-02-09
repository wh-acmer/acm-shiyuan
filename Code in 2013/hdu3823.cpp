/*
    water
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
#define maxn 12000000
bool vis[maxn];
vector<pair<int,int> >ans[160];
int main()
{
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=0;
    v.clear();
    for(int i=2;i<maxn;i++)
    {
        if(vis[i])
        {
            v.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
                vis[j]=0;
        }
    }
    //cout<<v.size()<<endl;
    for(int i=0;i<160;i++)
        ans[i].clear();
    int tmp;
    for(int i=0;i<v.size()-1;i++)
    {
        tmp=v[i+1]-v[i];
        if(tmp<=150)
            ans[tmp].push_back(make_pair(v[i],v[i+1]));
    }
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        bool can=0;
        printf("Case %d: ",cas);
        for(int i=0;i<ans[b-a].size();i++)
        {
            if(ans[b-a][i].first >= a && ans[b-a][i].second >= b)
            {
                can=1;
                printf("%d\n",ans[b-a][i].first-a);
                break;
            }
        }
        if(!can)
            printf("-1\n");
    }
    return 0;
}
