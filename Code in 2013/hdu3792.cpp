/*
 water
*/
#include <string.h>
#include <stdio.h>
#define maxn 100010
int prime[maxn],pprime[maxn];
int tag[maxn];
int num;
void Prime()
{
    memset(tag,1,sizeof(tag));
    tag[0]=tag[1]=0;
    num=0;
    for(int i=1;i*i<=maxn;i++)
        if(tag[i])
        {
            for(int j=2*i;j<=maxn;j+=i)
                tag[j]=0;
        }
    for(int i=1;i<=maxn;i++)
        if(tag[i])
            prime[++num]=i;
}
int main()
{
    Prime();
    for(int i=1;i<=num;i++)
    pprime[i]=prime[i+1]-prime[i];
    int n;
    while(scanf("%d",&n),n>=0)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(prime[i+1]>n)
                break;
            if(pprime[i]==2)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
