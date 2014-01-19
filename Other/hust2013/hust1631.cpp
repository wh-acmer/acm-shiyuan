/*
    题意：求连通所有点需要的最小权值和
    思路：裸的kruskal，直接套模版
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 110
struct node{
    int st,ed,w;
    friend bool operator <(const node& a,const node& b){
        return a.w>b.w;
    }
};
priority_queue<node>q;
int father[maxn];
int get_father(int cur){
    return cur==father[cur]?cur:father[cur]=get_father(father[cur]);
}
int join(int st,int ed){
    int root1=get_father(st);
    int root2=get_father(ed);
    if(root1==root2) return 0;
    father[root1]=root2;
    return 1;
}
int kruskal(){
    int ans=0;
    node cur;
    while(!q.empty()){
        cur=q.top();
        q.pop();
        if(join(cur.st,cur.ed)){
            ans+=cur.w;
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    node a;
    while(T--){
        while(!q.empty()) q.pop();
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=0;i<=n;i++) father[i]=i;
        for(int i=0;i<m;i++) {
            scanf("%d%d%d",&a.st,&a.ed,&a.w);
            q.push(a);
        }
        bool ok=true;
        int ans=kruskal();
        for(int i=2;i<=n;i++) if(get_father(i)!=get_father(i-1)) ok=false;
        if(ok)  printf("%d\n",ans);
        else printf("I'm not sure.\n");
    }
    return 0;
}
