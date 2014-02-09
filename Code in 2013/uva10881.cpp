/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define maxn 10001
using namespace std;
struct Ant
{
    int now;
    int dir;
    int no;
};
bool cmp(Ant a,Ant b)
{
    return a.now<b.now;
}
Ant ant[maxn],last[maxn];
int order[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++)
    {
        int l,t,n;
        scanf("%d%d%d",&l,&t,&n);
        char s[5];
        for(int i=1;i<=n;i++)
        {
            scanf("%d%s",&ant[i].now,s);
            ant[i].no=i;
            if(s[0]=='L')
                ant[i].dir=-1;
            else
                ant[i].dir=1;
            last[i]=ant[i];
            last[i].now+=t*last[i].dir;
        }
        sort(ant+1,ant+n+1,cmp);
        for(int i=1;i<=n;i++)
            order[ant[i].no]=i;
        sort(last+1,last+n+1,cmp);
        for(int i=1;i<n;i++)
            if(last[i].now==last[i+1].now)
                last[i].dir=last[i+1].dir=0;
        printf("Case #%d:\n",cases);
        for(int i=1;i<=n;i++)
        {
            int x=order[i];
            if(last[x].now<0||last[x].now>l)
                printf("Fell off\n");
            else
            {
                printf("%d ",last[x].now);
                if(last[x].dir==0)
                    printf("Turning\n");
                else if(last[x].dir==-1)
                    printf("L\n");
                else
                    printf("R\n");
            }
        }
        printf("\n");
    }
    return 0;
}
