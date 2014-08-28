#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100010
typedef long long LL;
LL a[maxn];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(a,0,sizeof(a));
        int m,l,r,x;
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&l,&r,&x);
            a[l]+=x;
            a[r+1]-=x;
        }
        for(int i=1;i<maxn;i++){
            a[i]+=a[i-1];
        }
        for(int i=maxn-2;i>=0;i--){
            a[i]+=a[i+1];
        }
        scanf("%d",&m);
        int ans=0;
        LL y;
        while(m--){
            scanf("%I64d%d",&y,&l);
            if(a[l]<y){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
