/*
    water

    若n是friend数，那么令n=a+b+a*b=(a+1)*(b+1)-1;
    同理 a可以表示成a=(c+1)*(d+1)-1 b可以表示成b=(e+1)*(f+1)-1;
    带回到式子n里面 n=(c+1)*(d+1)*(e+1)*(f+1)-1;
    同样，如果一直推导到最后，这个数如果满足加1能够表示成2的幂乘以3的幂，就是friend数
*/
#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            printf("NO!\n");
            continue;
        }
        n++;
        while(n%2==0)
        {
            n/=2;
        }
        while(n%3==0)
        {
            n/=3;
        }
        if(n==1)
        printf("YES!\n");
        else
        printf("NO!\n");
    }
    return 0;
}
