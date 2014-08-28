/*
 *=====================
 *File Name:a.cpp
 *Author: qqspeed
 *Date: 2014年 08月 21日 星期四 14:13:23 CST
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
#include <assert.h>
#include <limits.h>
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

inline void output(ll x){
    if(x<0){
        putchar('-');x=-x;
    }
    int len=0,data[21];
    while(x){
        data[len++]=x%10;x/=10;
    }
    if(!len)    data[len++]=0;
    while(len--)
        putchar(data[len]+48);
    putchar('\n');
}


const int N=50005;
ll val[N<<2],sum[N<<2];
int lazy[N<<2];
int T,n,q;
ll x,y;
char op[2];

inline void push_up(int t){
    val[t]=max(val[L],val[R]);
    sum[t]=sum[L]+sum[R];
}

inline void push_down(int t){
    if(lazy[t]!=0){
        lazy[L]+=lazy[t];
        lazy[R]+=lazy[t];
        sum[L]*=(1LL<<lazy[t]);
        sum[R]*=(1LL<<lazy[t]);
        val[L]*=(1LL<<lazy[t]);
        val[R]*=(1LL<<lazy[t]);
        lazy[t]=0;
    }
}

inline void build(int t,int x,int y){
    lazy[t]=0;
    sum[t]=y-x+1;
    val[t]=1;
    if(x!=y){
        MID(x,y);
        build(L,x,mid);
        build(R,mid+1,y);
    }
}

inline void modefiy1(int t,int l,int r,int x,ll v){
    if(l==r) {val[t]+=v,sum[t]+=v;}
    else{
        push_down(t);
        MID(l,r);
        if(x<=mid) modefiy1(L,l,mid,x,v);
        else modefiy1(R,mid+1,r,x,v);
        push_up(t);
    }
}

inline void modefiy(int t,int l,int r,int x,int y){
    if(l>=x && r<=y){
        lazy[t]++;
        val[t]<<=1;
        sum[t]<<=1;
    }
    else{
        push_down(t);
        MID(l,r);
        if(y<=mid) modefiy(L,l,mid,x,y);
        else if(x>mid) modefiy(R,mid+1,r,x,y);
        else{
            modefiy(L,l,mid,x,mid);
            modefiy(R,mid+1,r,mid+1,y);
        }
        push_up(t);
    }
}

inline ll query(int t,int l,int r,int x,int y){
    if(l>=x && r<=y) return val[t];
    push_down(t);MID(l,r);
    if(y<=mid) return query(L,l,mid,x,y);
    else if(x>mid) return query(R,mid+1,r,x,y);
    else return max(query(L,l,mid,x,mid),query(R,mid+1,r,mid+1,y));
}

inline ll queryS(int t,int l,int r,int x,int y){
    if(l>=x && r<=y) return sum[t];
    push_down(t);MID(l,r);
    if(y<=mid) return queryS(L,l,mid,x,y);
    else if(x>mid) return queryS(R,mid+1,r,x,y);
    else return (queryS(L,l,mid,x,mid)+queryS(R,mid+1,r,mid+1,y));
}

inline int bs(int x,int y,ll v){
    while(x<=y){
        MID(x,y);
        ll v1=queryS(1,1,n,1,mid);
        if(v1<v) x=mid+1;
        else y=mid-1;
    }
    return x;
}

int main(){
    T=input();
    rep(ca,1,T+1){
        printf("Case #%d:\n",ca);
        //scanf("%d%d",&n,&q);
        n=input(),q=input();
        build(1,1,n);
        while(q--){
            //scanf("%s%d%d",op,&x,&y);
            scanf("%s%I64d%I64d",op,&x,&y);
            //x=input(),y=input();
            if(op[0]=='D'){
                int s=bs(1,n,x);
                int t=bs(1,n,y);
                //cout<<s<<" "<<t<<endl;
                if(s==t){
                    modefiy1(1,1,n,s,(y-x+1));
                }
                else{
                    ll del2,del1=queryS(1,1,n,1,s);
                    if(t-1>=1)
                        del2=y-queryS(1,1,n,1,t-1);
                    else del2=y;
                    modefiy1(1,1,n,s,(del1-x+1));
                    modefiy1(1,1,n,t,del2);
                    if(s+1<=t-1){
                        modefiy(1,1,n,s+1,t-1);
                    }
                }
            }
            else{
                int s=bs(1,n,x);
                int t=bs(1,n,y);
                ll ans;
                if(s==t) ans=y-x+1;
                else{
                    ll del1,del2;
                    del1=queryS(1,1,n,1,s)-x+1;
                    //cout<<del1<<endl;
                    if(t-1>=1) del2=y-queryS(1,1,n,1,t-1);
                    else del2=y;
                    //cout<<del2<<endl;
                    ans=max(del1,del2);
                    if(s+1<=t-1){
                        ans=max(ans,query(1,1,n,s+1,t-1));
                    }
                }
                output(ans);
            }
            //cout<<queryS(1,1,n,1,n)<<" z"<<endl;
            //rep(i,1,n+1) cout<<queryS(1,1,n,i,i)<<endl;
        }
    }
    return 0;
}
