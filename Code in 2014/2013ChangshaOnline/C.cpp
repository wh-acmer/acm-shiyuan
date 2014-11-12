#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const double eps=1e-15;
double r,g,b;
double h,s,l,v;
string str;
double fabs(double tmp)
{
    if(tmp>0)
        return tmp;
    return -tmp;
}
void Converting_HSV_to_RGB()
{

    s/=100.0;
    v/=100.0;
    double c=v*s;
    h/=60.0;
    double hh=h;
    while(hh+eps>=2)
        hh-=2;
    double x=c*(1-fabs(hh-1));
    if(h>=0 &&h<1 )
        r=c,g=x,b=0;
    else if(h<2)
        r=x,g=c,b=0;
    else if(h<3)
        r=0,g=c,b=x;
    else if(h<4)
        r=0,g=x,b=c;
    else if(h<5)
        r=x,g=0,b=c;
    else if(h<6)
        r=c,g=0,b=x;
    else
        r=0,g=0,b=0;
    double m=v-c;
    r+=m,g+=m,b+=m;
    r*=255.0,g*=255.0,b*=255.0;
}
void Converting_HSL_to_RGB()
{
    s/=100.0;
    l/=100.0;
    double c=(1-fabs(2*l-1))*s;
    h/=60.0;
    double hh=h;
    while(hh>=2)
        hh-=2;
    double x=c*(1-fabs(hh-1));
    if(h>=0 &&h<1 )
        r=c,g=x,b=0;
    else if(h<2)
        r=x,g=c,b=0;
    else if(h<3)
        r=0,g=c,b=x;
    else if(h<4)
        r=0,g=x,b=c;
    else if(h<5)
        r=x,g=0,b=c;
    else if(h<6)
        r=c,g=0,b=x;
    else
        r=0,g=0,b=0;
    double m=l-0.5*c;
    r+=m,g+=m,b+=m;
    r*=255,g*=255,b*=255;
}

void Convert_RGB_to_HSL()
{

    r/=255.0,g/=255.0,b/=255.0;
    double mx=max(max(r,g),b);
    double mi=min(min(r,g),b);
    l=0.5*(mx+mi);
    if(mx==mi)
        h=0;
    else if(mx==r && g>=b)
        h=60.0*(g-b)/(mx-mi)+0;
    else if(mx==r && g<b)
        h=60.0*(g-b)/(mx-mi)+360.0;
    else if(mx==g)
        h=60.0*(b-r)/(mx-mi)+120.0;
    else if(mx==b)
        h=60.0*(r-g)/(mx-mi)+240.0;
    if(fabs(l)<eps || mx==mi)
        s=0;
    else if(l>0 && l<=0.5)
        s=(mx-mi)/2.0/l;
    else
        s=(mx-mi)/(2.0-2.0*l);
}
void Convert_RGB_to_HSV()
{

    r/=255.0,g/=255.0,b/=255.0;
    double mx=max(max(r,g),b);
    double mi=min(min(r,g),b);
    if(fabs(mx)<eps)
        s=0;
    else
        s=1-mi/mx;
    v=mx;
    if(mx==mi)
        h=0;
    else if(mx==r && g>=b)
        h=60.0*(g-b)/(mx-mi)+0.0;
    else if(mx==r && g<b)
        h=60.0*(g-b)/(mx-mi)+360.0;
    else if(mx==g)
        h=60.0*(b-r)/(mx-mi)+120.0;
    else if(mx==b)
        h=60.0*(r-g)/(mx-mi)+240.0;
}

int main()
{
    string need;
    while (cin>>need)
    {
        if(need=="RGB")
        {
            cin>>str;
            if(str=="HSL")
            {
                scanf("%lf %lf%% %lf%%",&h,&s,&l);
                Converting_HSL_to_RGB();
                printf("RGB %.lf %.lf %.lf\n",r,g,b);
            }
            else if(str=="HSV")// HSV
            {
                scanf("%lf %lf%% %lf%%",&h,&s,&v);
                Converting_HSV_to_RGB();
                printf("RGB %.lf %.lf %.lf\n",r,g,b);
            }
            else
            {
                cout<<need;
                char sb[1000];
                gets(sb);
                puts(sb);
            }
        }
        else if(need=="HSV")
        {
            cin>>str;
            if(str=="RGB")
            {
                scanf("%lf %lf %lf",&r,&g,&b);
                Convert_RGB_to_HSV();
                printf("HSV %.lf %.lf%% %.lf%%\n",h,s*100,v*100);
            }
            else if(str=="HSL")
            {
                scanf("%lf %lf%% %lf%%",&h,&s,&l);
                Converting_HSL_to_RGB();
                Convert_RGB_to_HSV();
                printf("HSV %.lf %.lf%% %.lf%%\n",h,s*100,v*100);
            }
            else
            {
                cout<<need;
                char sb[1000];
                gets(sb);
                puts(sb);
            }
        }
        else
        { // HSL
            cin>>str;
            if(str=="RGB")
            {
                scanf("%lf %lf %lf",&r,&g,&b);
                Convert_RGB_to_HSL();
                printf("HSL %.lf %.lf%% %.lf%%\n",h,s*100,l*100);
            }
            else if(str=="HSV")
            {
                scanf("%lf %lf%% %lf%%",&h,&s,&v);
                Converting_HSV_to_RGB();
                Convert_RGB_to_HSL();
                printf("HSL %.lf %.lf%% %.lf%%\n",h,s*100,l*100);
            }
            else
            {
                cout<<need;
                char sb[1000];
                gets(sb);
                puts(sb);
            }
        }
    }
    return 0;
}
