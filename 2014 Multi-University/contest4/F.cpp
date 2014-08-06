/*
 *=====================
 *File Name:a.cpp
 *Author: qqspeed
 *Date: 2014年 07月 31日 星期四 12:08:41 CST
 *=====================
 */
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

const int N=100005;
int Min[N<<2],Max[N<<2];
int lazy[N<<2];
int a[N];
int t,n,q;
int op,l,r,x;

inline int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

inline void push_up(int t){
    Min[t]=min(Min[L],Min[R]);
    Max[t]=max(Max[L],Max[R]);
}

inline void push_down(int t){
    if(lazy[t]!=-1){
        lazy[L]=lazy[t];
        lazy[R]=lazy[t];
        Min[L]=Max[L]=lazy[t];
        Min[R]=Max[R]=lazy[t];
        lazy[t]=-1;
    }
}

inline void build(int t,int l,int r){
    lazy[t]=-1;
    if(l==r) Min[t]=Max[t]=a[l];
    else{
        MID(l,r);
        build(L,l,mid);
        build(R,mid+1,r);
        push_up(t);
    }
}

inline void change(int t,int l,int r,int x,int y,int a){
    if(l>=x && r<=y){
        Max[t]=Min[t]=a;
        lazy[t]=a;
        return;
    }
    push_down(t);
    MID(l,r);
    if(y<=mid) change(L,l,mid,x,y,a);
    else if(x>mid) change(R,mid+1,r,x,y,a);
    else{
        change(L,l,mid,x,mid,a);
        change(R,mid+1,r,mid+1,y,a);
    }
    push_up(t);
}

inline void changegcd(int t,int l,int r,int x,int y,int a){
    if(Max[t]<=a) return;
    if(l>=x && r<=y && Max[t]==Min[t]){
        int nxt=gcd(Max[t],a);
        change(1,1,n,l,r,nxt);
        return;
    }
    if(l==r){
        if(Max[t]>a) Max[t]=Min[t]=gcd(Max[t],a);
        return;
    }
    push_down(t);
    MID(l,r);
    if(y<=mid) changegcd(L,l,mid,x,y,a);
    else if(x>mid) changegcd(R,mid+1,r,x,y,a);
    else{
        changegcd(L,l,mid,x,mid,a);
        changegcd(R,mid+1,r,mid+1,y,a);
    }
    push_up(t);
}

inline int query(int t,int l,int r,int x){
    if(l==r) return Max[t];
    push_down(t);
    MID(l,r);
    if(x<=mid) return query(L,l,mid,x);
    else return query(R,mid+1,r,x);
}


int main(){
    t=input();
    while(t--){
        n=input();
        rep(i,1,n+1) a[i]=input();
        build(1,1,n);
        q=input();
        while(q--){
            op=input(),l=input(),r=input(),x=input();
            if(op==1) change(1,1,n,l,r,x);
            else changegcd(1,1,n,l,r,x);
        }
        rep(i,1,n+1){
            printf("%d ",query(1,1,n,i));
        }
        puts("");
    }
    return 0;
}
