#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 200010
using namespace std;
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int n_a=0,n_b=0,x,a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        if(x==1)
            n_a++;
        else
            n_b++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if((b-a+1)&1)
            printf("0\n");
        else if(n_a<(b-a+1)/2||n_b<(b-a+1)/2)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
