#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef __int64 LL;
int main(){
    LL n,ans,tmp;
    while(scanf("%I64d",&n)!=EOF){
        if(n==0){
            printf("1\n");
            continue;
        }
        tmp=(LL)(n/sqrt(2.0));
        ans=2*tmp+1;
        if((LL)sqrt(n*n-tmp*tmp)==tmp) ans--;
        printf("%I64d\n",ans*4);
    }
    return 0;
}
