#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
#define N 40
#define inf 1e30
#define eps 1e-6
#define pi acos(-1.0)
struct point{
    double x,y,d;
}p[N],q[1010],tp;
double sq(double x){
    return x*x;
}
double dis(point p1,point p2){
    return sqrt(sq(p1.x-p2.x)+sq(p1.y-p2.y));
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double w,h;
        scanf("%lf%lf",&w,&h);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&q[i].x,&q[i].y);
        }
        for(int i=0;i<N;i++){
            p[i].x=(rand()%1000+1)/1000*w;
            p[i].y=(rand()%1000+1)/1000*h;
            p[i].d=inf;
            for(int j=0;j<n;j++){
                p[i].d=min(p[i].d,dis(p[i],q[j]));
            }
        }
        double step=max(w,h)/sqrt(n+0.0);
        while(step>eps){
            for(int i=0;i<N;i++){
                double x=p[i].x;
                double y=p[i].y;
                int cas=N;
                while(cas--){
                    double cnt=(rand()%1000+1)/1000.0*2*pi;
                    x+=cos(cnt)*step;
                    y+=sin(cnt)*step;
                    if(x<0 || y<0 || x>w || y>h) continue;
                    double ans=inf;
                    tp.x=x;
                    tp.y=y;
                    for(int j=0;j<n;j++){
                        ans=min(ans,dis(tp,q[j]));
                    }
                    if(ans>p[i].d){
                        p[i].d=ans;
                        p[i].x=x;
                        p[i].y=y;
                    }
                }
            }
            step*=0.8;
        }
        double ans=0;
        double x=0,y=0;
        for(int i=0;i<N;i++){
            if(p[i].d>ans){
                ans=p[i].d;
                x=p[i].x;
                y=p[i].y;
            }
        }
        printf("The safest point is (%.1f, %.1f).\n",x,y);
    }
    return 0;
}
