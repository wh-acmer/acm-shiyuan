/*
    water
    求某个数到最后中间出现不同数字的个数
    倒着预处理一下
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
#define maxn 100001
int a[maxn],dp[maxn];
set<int>s;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        s.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dp[n]=1;
        s.insert(a[n]);
        for(int i=n-1;i>=1;i--){
            if(s.count(a[i])) dp[i]=dp[i+1];
            else{
                s.insert(a[i]);
                dp[i]=dp[i+1]+1;
            }
        }
        while(m--){
            scanf("%d",&a[0]);
            printf("%d\n",dp[a[0]]);
        }
    }
    return 0;
}
