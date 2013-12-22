#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int fun(int a,int b){
    int ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%10;
        else    b/=2,a=(a*a)%10;
    }
    return ans;
}
int solve(int n,int k){
    k%=4;
    k+=4;
    if(n>10) return (((n/10)*solve(10,k))%10+solve(n%10,k))%10;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+fun(i,k))%10;
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        printf("%d\n",solve(n,k));
    }
    return 0;
}
