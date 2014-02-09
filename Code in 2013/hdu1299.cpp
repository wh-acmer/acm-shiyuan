/*
 water
*/

/*
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 100000
int tag[maxn];
int prime[maxn];
int miao;
void Prime()
{
    miao=0;
    memset(tag,1,sizeof(tag));
    tag[0]=tag[1]=0;
    for(int i=2;i<=sqrt(maxn*1.0);i++)
    {
        if(tag[i])
        {
            prime[++miao]=i;
            for(int j=i;j<maxn;j+=i)
            tag[i]=0;
        }
    }
}
int main()
{
    int t,p=0;
    scanf("%d",&t);
    int n,temp;
    Prime();
    while(t--)
    {
        scanf("%d",&n);
        int ans=1,temp;
        for(int i=1;i<=miao&prime[i]<=n;i++)
        {
            temp=1;
            while(n%prime[i]==0&&n!=0)
            {
                n/=prime[i];
                temp+=2;
            }
            ans*=temp;
        }
        if(n!=1) ans*=3;
        printf("Scenario #%d:\n%d\n\n",++p,(ans+1)/2);
    }
    return 0;
}
*/

#include <stdio.h>
#include <math.h>
int main()
{
    int t,p=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,s=1,m;
        scanf("%d",&n);
        for(int i=2;i<=sqrt(n*1.0)+1;i++)
        {
            if(n%i==0)
            {
                m=0;
                while(n%i==0)
                {
                    n/=i;
                    m++;
                }
                s*=(2*m+1);
            }
            if(n==1) break;
        }
        if(n!=1) s*=3;
        printf("Scenario #%d:\n%d\n\n",++p,(s+1)/2);
    }
    return 0;
}
