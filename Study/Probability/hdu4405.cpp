#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
map<int,int>mp;
map<int,int>real;
#define maxn 100010
double dp[maxn];
int flight(int x){
    if(real.count(x))
        return real[x];
    if(mp.count(x))
        return real[x]=flight(mp[x]);
    return real[x]=x;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        mp.clear();
        real.clear();
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x]=y;
        }
        for(int i=n;i>=0;i--){
            flight(i);
        }
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            dp[i]=1;
            for(int j=1;j<=6;j++){
                if(real[i+j]!=0)
                    dp[i]+=1.0/6*dp[real[i+j]];
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}
