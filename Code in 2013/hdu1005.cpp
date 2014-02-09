/*
    water
*/
#include <stdio.h>
int f[1010];
int main()
{
    int a,b,n,i;
    f[1]=1;
    f[2]=1;
    while(scanf("%d%d%d",&a,&b,&n)!=EOF,a||b||n)
    {
        n%=49;
        for(i=3;i<=n;i++)
        {
            f[i]=((a*f[i-1])+(b*f[i-2]))%7;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
