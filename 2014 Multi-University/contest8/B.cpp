#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 510
struct point  {
    int x,y;
}p[maxn],pnt[maxn],res[maxn];
bool operator <(const point &l,const point &r)  {
    return l.y<r.y||(l.y==r.y&&l.x<r.x);
}
bool multi(point p1,point p2,point p0)  {
    return (p1.x-p0.x)*(p2.y-p0.y)>=(p2.x-p0.x)*(p1.y-p0.y);
}
int graham(int n) {
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0;
    res[0]=pnt[0];
    if(n==1) return 1;
    res[1]=pnt[1];
    if(n==2) return 2;
    res[2]=pnt[2];
    for(i=2;i<n;i++)
    {
        while(top&&multi(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    len=top;
    res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--)
    {
        while(top!=len&&multi(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    return top;
}
int v[maxn],vis[maxn];
int on_seg(point p1,point p2,point p){
    return (p2.y-p1.y)*(p1.x-p.x)==(p2.x-p1.x)*(p1.y-p.y);
}
int main(){
    int n,cas=0;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        int mx=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&p[i].x,&p[i].y,&v[i]);
            if(v[i]>mx) mx=v[i];
        }
        int num=0;
        for(int i=0;i<n;i++){
            if(v[i]==mx){
                pnt[num].x=p[i].x;
                pnt[num].y=p[i].y;
                num++;
            }
        }
        memset(vis,0,sizeof(vis));
        int po=graham(num);
        for(int i=0;i<n;i++){
            if(v[i]==mx){
                for(int j=0;j<po;j++)
                    if(on_seg(res[j],res[(j+1)%po],p[i])){
                        vis[i]=1;
                    }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]){
                int can=0;
                for(int j=0;j<n;j++){
                    if(j!=i && p[i].x==p[j].x && p[i].y==p[j].y && mx==v[j]) {
                        can=1;
                    }
                }
                if(can){
                    for(int j=0;j<n;j++){
                        if(p[i].x==p[j].x && p[i].y==p[j].y && mx==v[j]) {
                            vis[j]=0;
                        }
                    }
                }
            }
        }
        if(mx==0) memset(vis,0,sizeof(vis));
        printf("Case #%d: ",++cas);
        for(int i=0;i<n;i++) printf("%d",vis[i]);
        printf("\n");
    }
    return 0;
}
