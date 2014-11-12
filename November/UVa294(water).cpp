// Divisors
// http://uva.onlinejudge.org/external/2/294.pdf
// water


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 40000
const LL mod=100000007;
bool vis[N];
vector<int>v;
void init(){
    memset(vis,true,sizeof vis);
    vis[0]=vis[1]=false;
    for(int i=2;i<N;i++){
        if(vis[i]){
            v.push_back(i);
            for(int j=2*i;j<N;j+=i){
                vis[j]=false;
            }
        }
    }
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        LL l,r;
        scanf("%lld%lld",&l,&r);
        LL ans=l,ans_count=0;
        for(LL o=l;o<=r;o++){
            LL n=o;
            LL pnt=1;
            for(int i=0;i<v.size();i++){
                if(n%v[i]==0){
                    int cnt=0;
                    while(n%v[i]==0){
                        n/=v[i];
                        cnt++;
                    }
                    pnt*=(cnt+1);
                }
            }
            if(n!=1) pnt*=2;
            if(pnt>ans_count){
                ans_count=pnt;
                ans=o;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,r,ans,ans_count);
    }
    return 0;
}
