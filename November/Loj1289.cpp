// http://lightoj.com/login_main.php?url=volume_showproblem.php?problem=1289
// LCM from 1 to n
// math

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 100000000
#define M 5800000
#define i64 long long
#define u32 unsigned int
int prime[M];
u32 res[M];
u32 tag[N/64+5];
int cnt=0;
void init(){
    prime[cnt++]=res[0]=2;
    for(int i=3;i<N;i+=2){
        if(!(tag[i>>6]&(1<<(i/2%32)))){
            prime[cnt++]=i;
            res[cnt-1]=res[cnt-2]*i;
            for(int j=i*3;j<N;j+=2*i){
                tag[j>>6]|=(1<<(j/2%32));
            }
        }
    }
}
u32 solve(int n){
    int index=upper_bound(prime,prime+cnt,n)-prime-1;
    u32 ans=res[index];
    for(int i=0;i<cnt && (i64)prime[i]*prime[i]<=n;i++){
        u32 x=prime[i];
        while(n>=(LL)x*prime[i]){
            x*=prime[i];
        }
        ans=ans*(x/prime[i]);
    }
    return ans;
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %u\n",cas,solve(n));
    }
    return 0;
}
