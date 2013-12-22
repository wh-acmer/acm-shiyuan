#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf (1<<30)
struct Tree{
    int l,r,mi,mx;
}tree[maxn<<2];
void pushup(int rt){
    tree[rt].mi=min(tree[rt<<1].mi,tree[rt<<1|1].mi);
    tree[rt].mx=max(tree[rt<<1].mx,tree[rt<<1|1].mx);
}
void build(int l,int r,int rt){
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r){
        scanf("%d",&tree[rt].mx);
        tree[rt].mi=tree[rt].mx;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int query(int x,int y,int rt,int tag){
    int l=tree[rt].l;
    int r=tree[rt].r;
    if(l==x && y==r){
        if(tag==1) return tree[rt].mx;
        else return tree[rt].mi;
    }
    int m=(l+r)>>1;
    int ans;
    if(tag==1){
        ans=-inf;
        if(x<=m) ans=max(ans,query(x,min(m,y),rt<<1,1));
        if(m<y) ans=max(ans,query(max(m+1,x),y,rt<<1|1,1));
    }
    else{
        ans=inf;
        if(x<=m) ans=min(ans,query(x,min(m,y),rt<<1,-1));
        if(m<y) ans=min(ans,query(max(m+1,x),y,rt<<1|1,-1));
    }
    return ans;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        build(0,n-1,1);
        int T;
        scanf("%d",&T);
        int x,y;
        while(T--){
            scanf("%d%d",&x,&y);
            if(x==0 && y==n-1){
                printf("%.1lf\n",(query(0,n-1,1,1)+query(0,n-1,1,-1))/2.0);
                continue;
            }
            int ans=query(x,y,1,-1);
            int tmp=0;
            if(x-1>=0) tmp=max(tmp,query(0,x-1,1,1));
            if(y+1<=n-1) tmp=max(tmp,query(y+1,n-1,1,1));
            double last=max(0.0+ans+tmp,(query(x,y,1,1)+query(x,y,1,-1))/2.0);
            printf("%.1lf\n",last);
        }
    }
    return 0;
}
