#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define MAX_V 10100
#define INF 100000000
struct edge{ int to,cost; };
typedef pair<int,int>P;
int V,D;
vector<edge>G[MAX_V];
int d[MAX_V];
priority_queue<P,vector<P>,greater<P> >que;
void dijkstra(int s){
    fill(d,d+MAX_V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
void init(){
    for(int i=0;i<MAX_V;i++) G[i].clear();
    while(!que.empty()) que.pop();
}
int main(){
    int T,x,y,val;
    while(scanf("%d%d%d",&T,&V,&D)!=EOF){
        init();
        for(int i=0;i<T;i++){
            scanf("%d%d%d",&x,&y,&val);
            edge ed; ed.cost=val,ed.to=y;
            edge edd; edd.cost=val,edd.to=x;
            G[x].push_back(ed);
            G[y].push_back(edd);
        }
        int ans=INF;
        scanf("%d",&y);
        for(int i=1;i<V;i++){
            scanf("%d",&x);
            edge ed; ed.cost=0,ed.to=x;
            G[y].push_back(ed);
        }
        dijkstra(y);
        for(int i=0;i<D;i++){
            scanf("%d",&x);
            ans=min(ans,d[x]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
