#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%100;
        else b/=2,a=(a*a)%100;
    }
    return ans;
}
int main(){
    int T;
    while(scanf("%d",&T)!=EOF && T){
        int cas=0; LL n;
        while(T--){
            scanf("%I64d",&n);
            printf("Case %d: %I64d\n",++cas,(Pow(2,n-1)+Pow(4,n-1))%100);
        }
        printf("\n");
    }
    return 0;
}
