#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define maxn 100010
int a[maxn*2];
int main(){
    int n,x,q,l,r;
    while(scanf("%d%d",&n,&q)!=EOF){
        memset(a,0,sizeof(a));
        while(n--){
            scanf("%d",&x);
            a[x]++;
        }
        while(q--){
            scanf("%d%d%d",&l,&r,&x);
            for(int i=r;i>=l;i--){
                a[i+x]+=a[i];
                a[i]=0;
            }
        }
        long long ans=0;
        for(long long i=0;i<maxn*2;i++)
            ans+=i*a[i];
        printf("%lld\n",ans);
    }
    return 0;
}
