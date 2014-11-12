//一个数学结论：一个素数p的原根的个数等于euler（p-1）
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int euler(int x)
{
    int i,res=x;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    if(x>1)
        res=res/x*(x-1);
    return res;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",euler(n-1));
    }
    return 0;
}
