#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 1010;
const int INF = 1000000000;

struct Edge{
    int v,next;
    int cap;
    int x,y;
}edge[505*505*2];

int res[maxn][maxn];
int n,m,k;

int head[maxn];
int cnt;

int s,t,nv;
int gap[maxn],dis[maxn],cur[maxn],pre[maxn];

void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
}

void add(int u,int v,int cap,int x,int y){
    edge[cnt].v=v;edge[cnt].cap=cap;
    edge[cnt].x=x;edge[cnt].y=y;
    edge[cnt].next=head[u];head[u]=cnt++;
}

void addedge(int u,int v,int cap,int x,int y){
    add(u,v,cap,-1,-1);
    add(v,u,0,x,y);
}

int isap(){
    memset(gap,0,sizeof(gap));
    memset(dis,0,sizeof(dis));
    for(int i=0;i<nv;i++)
        cur[i]=head[i];
    int u = pre[s] = s;
    gap[0]=nv;
    int aug = INF,maxflow = 0;
    while(dis[s]<nv){
        while(cur[u]!=-1){
            int i=cur[u];
            int v=edge[i].v;
            if(edge[i].cap && dis[u] == dis[v]+1){
                pre[v]=u;
                u=v;
                aug = min(aug,edge[i].cap);
                if(v==t){
                    maxflow+=aug;
                    for(u=pre[u];v!=s;v=u,u=pre[u]){
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap +=aug;
                    }
                    aug = INF;
                }
                continue;
            }
            cur[u]=edge[i].next;
        }
        int mindis = nv;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap && mindis>dis[v]){
                mindis=dis[v];
                cur[u]=i;
            }
        }
        if((--gap[dis[u]])==0)
            break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return maxflow;
}
int myh[maxn];
int tim;
bool bfs(int u){
    ++tim;
    queue<int> q;
    for(int i=head[u];~i;i=edge[i].next){
        int v = edge[i].v;
        if(!edge[i].cap) continue;
        q.push(v);
        myh[v] = tim;
    }
    ++tim;
    int bg = u;
    while(!q.empty()){
        u = q.front();q.pop();
        for(int i=head[u];~i;i=edge[i].next){
            int v = edge[i].v;
            if(!edge[i].cap) continue;
            if(v == bg && myh[u] != tim-1)
                return true;
            if(myh[v] != tim && myh[v] != tim-1){
                myh[v] = tim;
                q.push(v);
            }
        }
    }
    return false;
}
bool bfs2(){
    for(int i=1;i<=10;i++){
        if(i<=n && bfs(i))
            return true;
        if(i<=m && bfs(i+n))
            return true;
    }
    return false;
}
void solve(int sum0,int sum1){
    int ans=isap();
    if(ans!=sum0 || ans!=sum1){
        puts("So naive!");
    }
    else {
        for(int i=0;i<cnt;i++){
            if(edge[i].x!=-1){
                res[edge[i].x][edge[i].y]=edge[i].cap;
                //printf("(%d,%d)\n",edge[i].x,edge[i].y);
            }
        }
        int nans = bfs2();
        if(nans){
            puts("So young!");
            return;
        }
        puts("So simple!");
    }
}
inline int input(){
    int ret=0;bool isN=0;char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') isN=1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    return isN?-ret:ret;
}
int main() {
    int T,cas=0; T=input(); k=9;
    while(T--){
        n=input(),m=input();
        nv=n+m+2;
        init();
        s=0;t=n+m+1;
        int sum0=0;
        for(int i=1,tem;i<=n;i++){
            tem=input();
            addedge(0,i,tem,-1,-1);
            sum0+=tem;
        }
        int sum1=0;
        for(int i=1,tem;i<=m;i++){
            tem=input();
            addedge(i+n,t,tem,-1,-1);
            sum1+=tem;
        }
        printf("Case #%d: ",++cas);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                addedge(i,j+n,k,i,j);
        solve(sum0,sum1);
    }
    return 0;
}
