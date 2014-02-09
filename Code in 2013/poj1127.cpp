/*
    water
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define eps (1e-10)
using namespace std;
double add(double a,double b)
{
    if(abs(a+b)<eps*(abs(a)+abs(b)))
        return 0;
    return a+b;
}
struct P
{
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator + (P p){
        return P(add(x,p.x),add(y,p.y));
    }
    P operator - (P p){
        return P(add(x,-p.x),add(y,-p.y));
    }
    P operator * (double d){
        return P(x*d,y*d);
    }
    double dot(P p){
        return add(x*p.x,y*p.y);
    }
    double det(P p){
        return add(x*p.y,-y*p.x);
    }
};
bool on_seg(P p1,P p2,P q){
    return (p1-q).det(p2-q)==0 &&(p1-q).dot(p2-q)<=0;
}
P intersection(P p1,P p2,P q1,P q2){
    return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}
bool ans[15][15];
P p[15],q[15];
int n;
void solve()
{
    for(int i=0;i<n;i++)
    {
        ans[i][i]=1;
        for(int j=0;j<i;j++)
        {
            if((p[i]-q[i]).det(p[j]-q[j])==0)//Æ½ÐÐ
            {
                ans[i][j]=ans[j][i]=on_seg(p[i],q[i],p[j])||
                on_seg(p[i],q[i],q[j])||on_seg(p[j],q[j],p[i])
                ||on_seg(p[j],q[j],q[i]);
            }
            else
            {
                P r=intersection(p[i],q[i],p[j],q[j]);
                ans[i][j]=ans[j][i]=on_seg(p[i],q[i],r)&&on_seg(p[j],q[j],r);
            }
        }
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                ans[i][j]|=ans[i][k]&&ans[k][j];
            }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&q[i].x,&q[i].y);
        solve();
        int a,b;
        while(scanf("%d%d",&a,&b)!=EOF)
        {
            if(a==b&&a==0)
                break;
            if(ans[a-1][b-1])
                printf("CONNECTED\n");
            else
                printf("NOT CONNECTED\n");
        }
    }
    return 0;
}
