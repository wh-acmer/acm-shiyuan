#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int m,n,x,y,a,b;
    scanf("%d%d%d%d%d%d",&m,&n,&x,&y,&a,&b);
    int ggcd=gcd(a,b);
    a/=ggcd;
    b/=ggcd;
    int tmp=min(m/a,n/b);
    int width=tmp*a;
    int length=tmp*b;
    int x1,x2,y1,y2;
    if(width&1)
    {
        x1=x-width/2-1;
        x2=x1+width;
    }
    else
    {
        x1=x-width/2;
        x2=x1+width;
    }
    if(length&1)
    {
        y1=y-length/2-1;
        y2=y1+length;
    }
    else
    {
        y1=y-length/2;
        y2=y+length/2;
    }
    if(x1<0)
    {
        x2-=x1;
        x1=0;
    }
    if(y1<0)
    {
        y2-=y1;
        y1=0;
    }
    if(x2>m)
    {
        x1-=(x2-m);
        x2=m;
    }
    if(y2>n)
    {
        y1-=(y2-n);
        y2=n;
    }
    printf("%d %d %d %d\n",x1,y1,x2,y2);
    return 0;
}
