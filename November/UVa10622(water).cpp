// Perfect P-th Powers
// http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=25130
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N=(1<<16)+10;
bool vis[N];
vector<LL>v;
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
}
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    LL n;
    init();
    while(scanf("%lld",&n)&&n){
        int ans=-1;
        int tag=1;
        if(n<0){
            n*=-1;
            tag=-1;
        }
        for(int i=0;i<v.size() && v[i]*v[i]<=n;i++){
            if(n%v[i]==0){
                int cnt=0;
                while(n%v[i]==0){
                    n/=v[i];
                    cnt++;
                }
                if(ans==-1){
                    ans=cnt;
                }
                else{
                    ans=gcd(ans,cnt);
                }
            }
        }
        if(n!=1){
            if(ans==-1){
                ans=1;
            }
            else{
                ans=gcd(ans,1);
            }
        }
        if(tag==-1){
            while(ans%2==0){
                ans/=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
