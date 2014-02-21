#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 100010
struct point{
    double x,y;
}p[maxn],q[maxn];
double xmulti(point p1,point p2,point p0){
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}
int main(){
    int m,n;
    while(scanf("%d",&n)!=EOF){
        double _x2=n,_y2=n,_x1=0,_y1=0,_x0=0,_y0=0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            _x1-=2*p[i].x; _x0+=p[i].x*p[i].x;
            _y1-=2*p[i].y; _y0+=p[i].y*p[i].y;
        }
        double _x=-_x1/2/_x2,_y=-_y1/2/_y2;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%lf%lf",&q[i].x,&q[i].y);
        } q[m]=q[0];
        bool on = true;
        point pt; pt.x=_x,pt.y=_y;
        for(int i=0;i<m;i++){
            if(xmulti(pt,q[(i+1)%m],q[i])<0) on=false;
        }
        double ans=1e100;
        if(on) ans=_x2*_x*_x+_x1*_x+_x0+_y2*_y*_y+_y1*_y+_y0;
        else{
            for(int i=0;i<m;i++){
                double dx=q[i+1].x-q[i].x,dy=q[i+1].y-q[i].y,x=q[i].x,y=q[i].y;
                double _k=-(2*x*dx*_x2+_x1*dx+2*y*dy*_y2+_y1*dy)/(2*_x2*dx*dx+2*_y2*dy*dy);
                if(_k<0) _k=0; if(_k>1) _k=1;
                _x=q[i].x+_k*dx,_y=q[i].y+_k*dy;
                ans=min(ans,_x2*_x*_x+_x1*_x+_x0+_y2*_y*_y+_y1*_y+_y0);
            }
        }
        printf("%.8lf\n",ans);
    }
    return 0;
}
