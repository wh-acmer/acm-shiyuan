/*
    water
*/
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 1000001
int a[maxn];
char s[100];
bool is_ok(int a,int b,int c)
{
    return (a+b>c);
}
int n;
int in()
{
    char ch='0';
    int ans=0;
    while(ch>='0'&&ch<='9')
    {
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans;
}
void solve()
{
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
        a[i]=in();
    sort(a,a+n);
    if(n<=3)
        printf("The set is rejected.\n");
    else
    {
        if(is_ok(a[0],a[1],a[n-1]))
            printf("The set is rejected.\n");
        else
        {
            bool tag=0;
            for(int i=0;i<n-2;i++)
                if(is_ok(a[i],a[i+1],a[i+2]))
                {
                    tag=1;
                    printf("The set is accepted.\n");
                    break;
                }
            if(!tag)
                printf("The set is rejected.\n");
        }
    }
    printf("\n");
    return ;
}
int main()
{
    while(n=in())
    {
        solve();
    }
    return 0;
}
