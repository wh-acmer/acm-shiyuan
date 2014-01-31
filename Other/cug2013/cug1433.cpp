/*
    Í¹°ü
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 15001
#define pi acos(-1.0)
struct point{
    double x,y;
}pnt[maxn],res[maxn];
double multi(point sp,point ep,point op){
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool operator <(const point &l,const point &r){
    return l.y<r.y || (l.y==r.y && l.x<r.x);
}
double sqr(double x){
    return x*x;
}
double dis(point a,point b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
int graham(int n){
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0;
    res[0]=pnt[0];
    if(n==1) return 1;
    res[1]=pnt[1];
    if(n==2) return 2;
    res[2]=pnt[2];
    for(i=2;i<n;i++){
        while(top && multi(pnt[i],res[top],res[top-1])) top--;
        res[++top]=pnt[i];
    }
    len=top; res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
        while(top!=len &&multi(pnt[i],res[top],res[top-1])) top--;
        res[++top]=pnt[i];
    }
    return top;
}
int main(){
    int n,r;
    while(scanf("%d%d",&n,&r)!=EOF){
        double ans=pi*r*2;
        for(int i=0;i<n;i++) scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
        int po=graham(n);
        double tmp=0;
        for(int i=0;i+1<po;i++){
            tmp+=dis(res[i],res[i+1]);
        }
        if(n>1) tmp+=dis(res[0],res[po-1]);
        ans+=tmp;
        printf("%.2lf\n",ans);
    }
    return 0;
}
