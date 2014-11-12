#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;
#define N 20
#define inf 1e10
#define eps 1e-3
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
    double X,Y;
    int n;
    srand(time(0));
    while(scanf("%lf%lf%d",&X,&Y,&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&q[i].x,&q[i].y);
        }
        for(int i=0;i<N;i++){
            p[i].x=(rand()%1000+1)/1000.0*X;
            p[i].y=(rand()%1000+1)/1000.0*Y;
            double d=0;
            for(int j=0;j<n;j++){
                d=max(d,dis(p[i],q[j]));
            }
            p[i].d=d;
        }
        double step=max(X,Y);
        while(step>eps){
            for(int i=0;i<N;i++){
                double x=p[i].x;
                double y=p[i].y;
                int cas=N;
                while(cas--){
                    double cnt=(rand()%1000+1)/1000.0*2*pi;
                    double xx=x+cos(cnt)*step;
                    double yy=y+sin(cnt)*step;
                    if(xx<0 || yy<0 || xx>X || yy>Y) continue;
                    double d=0;
                    tp.x=xx;
                    tp.y=yy;
                    for(int j=0;j<n;j++){
                        d=max(d,dis(tp,q[j]));
                    }
                    if(d<p[i].d){
                        p[i].d=d;
                        p[i].x=xx;
                        p[i].y=yy;
                    }
                }
            }
            step*=0.8;
        }
        double d=inf,x,y;
        for(int i=0;i<N;i++){
            if(p[i].d<d){
                d=p[i].d;
                x=p[i].x;
                y=p[i].y;
            }
        }
        printf("(%.1f,%.1f).\n%.1f\n",x,y,d);
    }
    return 0;
}
