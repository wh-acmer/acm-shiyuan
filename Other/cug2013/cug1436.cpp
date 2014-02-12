/*
    by zhuhuangjian
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

#define N 5005
#define M 250
#define MM 20005
#define mod 1000000007

inline int input(){
    int ret=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
    return ret;
}

int n,m,k,cnt;
int a[MM],b[MM],p[N],pp[M],fac[1000000+2],mut[M][M];
int dp[N][M];
bool val[N][M],inq[N];

struct EDGE{
    int v,next;
}edge[MM],rev[MM];
int head[MM],head1[MM],e,ee;
inline void add(int u,int v){
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;

    rev[ee].v=u;
    rev[ee].next=head1[v];
    head1[v]=ee++;
}

inline int lcm(int a,int b){
    int x=a,y=b,t;
    while(y){
        t=x;
        x=y;
        y=t%x;
    }
    return a/x*b;
}

inline void Fun(int k){
    memset(fac,-1,sizeof(fac));
    cnt=0;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            pp[cnt]=i,fac[i]=cnt,cnt++;
            if(k/i!=i){
                pp[cnt]=k/i,fac[k/i]=cnt,cnt++;
            }
        }
    }
    for(int i=0;i<cnt;i++){
        for(int j=i;j<cnt;j++){
            mut[i][j]=mut[j][i]=lcm(pp[i],pp[j]);
        }
    }
}

inline void spfa(){
    queue<int>q;
    memset(inq,0,sizeof(inq));
    memset(val,0,sizeof(val));
    q.push(1);
    val[1][fac[p[1]]]=1;

    inq[1]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        inq[x]=0;
        for(int j=0;j<cnt;j++){
            if(!val[x][j]) continue;
            if(j==k) continue;
            for(int i=head[x];i!=-1;i=edge[i].next){
                int v=edge[i].v;
                if(pp[j] % p[v]==0) continue;
                int vv=mut[j][fac[p[v]]];
                if(k%vv!=0) continue;
                if(val[v][fac[vv]]==1) continue;
                val[v][fac[vv]]=1;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}

inline int dfs(int x,int y){
    if(dp[x][fac[y]]!=-1) return dp[x][fac[y]];
    int ans=0;
    for(int i=head1[x];i!=-1;i=rev[i].next){
        int v=rev[i].v;
        for(int j=0;j<cnt;j++){
            if(pp[j]%p[x]==0) continue;
            if(!val[v][j]) continue;
            if(mut[j][fac[p[x]]] == y){
                ans += dfs(v,pp[j]);
                ans%=mod;
            }
        }
    }
    return dp[x][fac[y]]=ans%mod;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        m=input(),k=input();
        Fun(k);

        for(int i=0;i<m;i++){
            a[i]=input(),b[i]=input();
        }
        for(int i=1;i<=n;i++){
            p[i]=input();
        }
        if(fac[p[1]]==-1 || fac[p[n]]==-1){
            puts("0");
        }
        else{
            memset(head,-1,sizeof(head));
            memset(head1,-1,sizeof(head1));
            e=ee=0;
            for(int i=0;i<m;i++){
                if(fac[p[a[i]]]==-1) continue;
                if(fac[p[b[i]]]==-1) continue;
                add(a[i],b[i]);
            }
            spfa();
            memset(dp,-1,sizeof(dp));
            memset(dp[1],0,sizeof(dp[1]));
            dp[1][fac[p[1]]]=1;
            printf("%d\n",dfs(n,k));
        }
    }
    return 0;
}
