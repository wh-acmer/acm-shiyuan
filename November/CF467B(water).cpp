// Fedor and New Game
// http://codeforces.com/problemset/problem/467/B
// water

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 1010
int a[N];
int count(int n){
    int ans=0;
    while(n){
        if(n&1){
            ans++;
        }
        n>>=1;
    }
    return ans;
}
int main(){
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(int i=m;i>=0;i--){
            scanf("%d",&a[i]);
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(count(a[0]^a[i])<=k) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
