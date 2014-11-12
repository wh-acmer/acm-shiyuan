#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
#define inf 1e20
#define eps 1e-9
double a,b,c,d,e,f;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={-1,1,-1,0,1,-1,0,1};
double dis(double x,double y,double z){
    return sqrt(x*x+y*y+z*z);
}
double getz(double x,double y){
    double A=c;
    double B=d*y+e*x;
    double C=a*x*x+b*y*y+f*x*y-1;
    double d=B*B-4*A*C;
    if(d<0){
        return inf;
    }
    double z1=(-B+sqrt(d))/2/A;
    double z2=(-B-sqrt(d))/2/A;
    if(fabs(z1)>fabs(z2)){
        return z2;
    }
    return z1;
}
double solve(){
    double step=1,r=0.98;
    double x=0,y=0,z,xx,yy,zz;
    while(step>eps){
        z=getz(x,y);
        for(int i=0;i<8;i++){
            xx=x+step*dx[i];
            yy=y+step*dy[i];
            zz=getz(xx,yy);
            if(fabs(zz-inf)<eps) continue;
            if(dis(xx,yy,zz)<dis(x,y,z)){
                x=xx;
                y=yy;
                z=zz;
            }
        }
        step*=r;
    }
    return dis(x,y,z);
}
int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)!=EOF){
        printf("%lf\n",solve());
    }
    return 0;
}
