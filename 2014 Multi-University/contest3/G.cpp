// by qqspeed
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,s,t) for(int i=s;i<t;i++)
#define red(i,s,t) for(int i=s-1;i>=t;i--)
#define ree(i,now) for(int i=head[now];i!=-1;i=edge[i].next)
#define clr(a,v) memset(a,v,sizeof a)
#define L t<<1
#define R t<<1|1
#define MID(l,r) int mid=(l+r)>>1
#define lowbit(x) (x&(-x))
#define SQR(a) ((a)*(a))

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

inline void output(int x){
    if(x<0){
        putchar('-');x=-x;
    }
    int len=0,data[11];
    while(x){
        data[len++]=x%10;x/=10;
    }
    if(!len)    data[len++]=0;
    while(len--)
        putchar(data[len]+48);
    putchar('\n');
}

inline ll Abs(ll a){
    return a>0?a:-a;
}

const int M=92;
map<ll,bool>mp;
ll f[100];
inline void init(){
    f[0]=f[1]=1;
    mp[1]=1;
    rep(i,2,M){
        f[i]=f[i-1]+f[i-2];
        mp[f[i]]=1;
    }
}

inline ll Find(ll p){
    if(p<=1) return 1;
    int id=lower_bound(f,f+M,p)-f;
    int iid=id-1;
    if(p-f[iid]<=f[id]-p) return f[iid];
    return f[id];
}

const int N=100005;
ll sum[N<<2],need[N<<2];
int lazy[N<<2];

inline void push_up(int t){
    sum[t]=sum[L]+sum[R];
    need[t]=need[L]+need[R];
}

inline void push_down(int t){
    if(lazy[t]){
        lazy[L]=lazy[R]=lazy[t];
        sum[L]+=need[L];
        sum[R]+=need[R];
        lazy[t]=0;
        need[L]=need[R]=0;
    }
}

inline void build(int t,int l,int r){
    lazy[t]=0;
    if(l==r){
        sum[t]=0;need[t]=1;
        return;
    }
    else{
        MID(l,r);
        build(L,l,mid);
        build(R,mid+1,r);
        push_up(t);
    }
}

inline void add(int t,int l,int r,int x,ll v){
    if(l==r){
        sum[t]+=v;
        need[t]=Find(sum[t])-sum[t];
        return;
    }
    push_down(t);
    MID(l,r);
    if(x<=mid) add(L,l,mid,x,v);
    else add(R,mid+1,r,x,v);
    push_up(t);
}

inline void change(int t,int l,int r,int x,int y){
    if(l>=x && r<=y){
        sum[t]+=need[t];
        lazy[t]=1;
        need[t]=0;
        return;
    }
    push_down(t);
    MID(l,r);
    if(y<=mid) change(L,l,mid,x,y);
    else if(x>mid) change(R,mid+1,r,x,y);
    else{
        change(L,l,mid,x,mid);
        change(R,mid+1,r,mid+1,y);
    }
    push_up(t);
}

inline ll query(int t,int l,int r,int x,int y){
    if(l>=x && r<=y){
        return sum[t];
    }
    push_down(t);
    MID(l,r);
    if(y<=mid) return query(L,l,mid,x,y);
    else if(x>mid) return query(R,mid+1,r,x,y);
    else return query(L,l,mid,x,mid)+query(R,mid+1,r,mid+1,y);
}

int n,m;
int op,x,y;
int d;

int main(){
    init();
    while(~scanf("%d%d",&n,&m)){
        build(1,1,n);
        while(m--){
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d",&x,&d);
                add(1,1,n,x,d*1LL);
            }
            else if(op==2){
                scanf("%d%d",&x,&y);
                printf("%I64d\n",query(1,1,n,x,y));
            }
            else{
                scanf("%d%d",&x,&y);
                change(1,1,n,x,y);
            }
        }
    }
    return 0;
}
