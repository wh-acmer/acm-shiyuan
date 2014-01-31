/*
    segment tree
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL;
const LL inf = 1000000000000000000LL;
struct Tree{
    int l,r,lazy;
    LL num,tag;
}tree[maxn<<2];
void pushup(int rt){
    tree[rt].num=min(tree[rt<<1].num,tree[rt<<1|1].num);
}
void build(int l,int r,int rt){
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].lazy=0;
    tree[rt].tag=0;
    if(l==r){
        scanf("%lld",&tree[rt].num);
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int x,int y,LL val,int rt){
    int l,r;
    l=tree[rt].l;
    r=tree[rt].r;
    if(x==l && y==r){
        tree[rt].lazy=1;
        tree[rt].tag+=val;
        tree[rt].num+=val;
        return ;
    }
    int m=(l+r)>>1;
    if(tree[rt].lazy){
        tree[rt].lazy=0;
        update(l,m,tree[rt].tag,rt<<1);
        update(m+1,r,tree[rt].tag,rt<<1|1);
        tree[rt].tag=0;
    }
    if(x<=m) update(x,min(m,y),val,rt<<1);
    if(y>m) update(max(m+1,x),y,val,rt<<1|1);
    pushup(rt);
}
LL query(int x,int y,int rt){
    int l=tree[rt].l;
    int r=tree[rt].r;
    if(l==x && y==r){
        return tree[rt].num;
    }
    int m=(l+r)>>1;
    if(tree[rt].lazy){
        tree[rt].lazy=0;
        update(l,m,tree[rt].tag,rt<<1);
        update(m+1,r,tree[rt].tag,rt<<1|1);
        tree[rt].tag=0;
    }
    LL ans=inf;
    if(x<=m) ans=min(ans,query(x,min(m,y),rt<<1));
    if(y>m) ans=min(ans,query(max(m+1,x),y,rt<<1|1));
    return ans;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        build(1,n,1);
        char op[100];
        int x,y;
        LL val;
        getchar();
        while(m--){
            gets(op);
            int l=strlen(op),now=0;
            x=0;
            while(op[now]!=' '){
                x=x*10+op[now]-'0';
                now++;
            }
            while(op[now]==' ') now++;
            y=0;
            while(now<l && op[now]!=' '){
                y=y*10+op[now]-'0';
                now++;
            }
            while(op[now]==' ') now++;
            if(now==l){
                if(x>y) printf("%lld\n",min(query(x+1,n,1),query(1,y+1,1)));
                else printf("%lld\n",query(x+1,y+1,1));
                continue;
            }
            while(op[now]==' ') now++;
            val=0;
            bool flag=true;
            if(op[now]=='-') flag=false,now++;
            while(now<l && op[now]!=' '){
                val=val*10+op[now]-'0';
                now++;
            }
            if(!flag) val*=-1;
            if(x<=y) update(x+1,y+1,val,1);
            else update(x+1,n,val,1),update(1,y+1,val,1);
        }
    }
    return 0;
}
