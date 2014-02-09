/*
    water

    f(x)=5*x^13+13*x^5+k*a*x
    f(x+1)=5*(x+1)^13+13*(x+1)^5+k*a*(x+1)
          =5*(x^13+13*x^12+……+13*x+1)+13*(x^5+5*x^4+10*x^3+10*x^2+5*x+1)+k*a*x+k*a
          =（5*x^13+13*x^5+k*a*x）+65*(…………)+18+a*k
    所以对于任意的x要保证 （18+a*k）%65=0
*/

#include <stdio.h>
int main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=1;i<=80;i++)
        {
            if((18+i*k)%65==0)
            {
                printf("%d\n",i);
                break;
            }
            if(i==80)
            printf("no\n");
        }
    }
    return 0;
}
