// Almost Prime Numbers
// http://uva.onlinejudge.org/external/105/10539.pdf
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
#define N 1000010
const LL mx=(LL)1e12;
bool vis[N];
vector<LL>v;
vector<LL>vt;
void init(){
    v.clear();
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
    vt.clear();
    for(int i=0;i<v.size()&&v[i]*v[i]<mx;i++){
        LL tmp=v[i]*v[i];
        while(tmp<mx){
            vt.push_back(tmp);
            tmp*=v[i];
        }
    }
    sort(vt.begin(),vt.end());
}
int solve(LL x){
    return upper_bound(vt.begin(),vt.end(),x)-vt.begin();
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        LL l,r;
        scanf("%lld%lld",&l,&r);
        printf("%d\n",solve(r)-solve(l-1));
    }
    return 0;
}
