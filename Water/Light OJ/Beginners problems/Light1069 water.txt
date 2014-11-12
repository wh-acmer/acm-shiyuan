#include <cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int ans=a-b;
        ans>0?ans:ans*=-1;
        ans+=a;
        ans*=4;
        ans+=19;
        printf("Case %d: ",i);
        printf("%d\n",ans);
    }
    return 0;
}
