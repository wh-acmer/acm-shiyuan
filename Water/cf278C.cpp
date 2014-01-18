/*
    题意：n个人每个人会几种语言，之间可能有交集，问需要多少个人去学某种语言，使得所有人能够交流
    思路：并查集 求能够分成多少块，ans=块数-1  特殊情况是所有人什么语言都不会，这时ans=总人数
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define maxn 110
set<int>v[maxn];
bool vis[maxn][maxn];
int pre[maxn];
int find(int x){
    if(x!=pre[x]){
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
void mix(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px>py) swap(px,py);
    pre[py]=px;
}
int main(){
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF){
        bool all_zero=true;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++){
            v[i].clear();
            scanf("%d",&x);
            if(x>0) all_zero=false;
            for(int j=0;j<x;j++){
                scanf("%d",&y);
                v[i].insert(y);
            }
        }
        for(int i=1;i<=n;i++)
            pre[i]=i;
        set<int>::iterator it;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(it=v[j].begin();it!=v[j].end();it++){
                    if(v[i].count(*it)){
                        mix(i,j);
                        break;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(pre[i]==i)
                ans++;
        }
        if(all_zero)    ans++;
        printf("%d\n",ans-1);
    }
    return 0;
}
