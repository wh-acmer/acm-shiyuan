/*
 *=====================
 *File Name:c.cpp
 *Author: qqspeed
 *Date: 2014年 08月 19日 星期二 12:16:37 CST
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

const int N=100000;
int n,m,k;
int x,a,b;
int c,d;
ll h;
ll b1[N+2],b2[N+2];
ll all;

inline void add(ll *b,int x,ll v){
    while(x<=n){
        b[x]+=v;
        x+=lowbit(x);
    }
}

inline ll sum(ll *b,int x){
    ll ans=0;
    while(x){
        //cout<<x<<endl;
        ans+=b[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(){
    while(1){
        n=input();
        if(!n) break;
        m=input();
        clr(b1,0);clr(b2,0);all=0;
        rep(i,0,m){
            a=input(),b=input(),x=input();
            all+=x*1LL*(b-a+1);
            c=n-b+1;d=n-a+1;
            add(b1,c,-x*1LL*(c-1));
            add(b2,c,x);
            add(b1,d+1,x*1LL*d);
            add(b2,d+1,-x);
        }
        k=input();
        int ans=0;
        while(k--){
            scanf("%I64d%d",&h,&x);
            //cout<<h<<" "<<x<<" "<<k<<endl;
            if(h>all) ans++;
            else{
                d=n-x+1;
                ll res=sum(b1,d)+sum(b2,d)*d;
                if(res<h) ans++;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
