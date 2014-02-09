/*
    water
    »ý·Ö
*/
#include <stdio.h>
double x1,x2,x3,y1,y2,y3;
double a,s,k;
double fuck(double x)
{
    return 1.0/3*a*(x-x1)*(x-x1)*(x-x1)+y1*x-1.0/2*k*(x-x3)*(x-x3)-y3*x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        k=(y2-y3)/(x2-x3);
        a=(y2-y1)/((x2-x1)*(x2-x1));
        s=fuck(x3)-fuck(x2);
        printf("%.2lf\n",s);
    }
    return 0;
}
