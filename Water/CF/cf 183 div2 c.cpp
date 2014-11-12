#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2==0)
        printf("-1\n");
    else
    {
        for(int i=0;i<n-1;i++)
            printf("%d ",i);
        printf("%d\n",n-1);
        for(int i=0;i<n-1;i++)
            printf("%d ",i);
        printf("%d\n",n-1);
        for(int i=0;i<n-1;i++)
            printf("%d ",i*2%n);
        printf("%d\n",(2*n-2)%n);
    }
    return 0;

}
