// Irrelevant Elements
// http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1666
// math

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define N 40000
bool vis[N];
vector<int>prime;
typedef pair<int,int>P;
vector<P>v;
vector<int>ans;
void init(){
    prime.clear();
    memset(vis,true,sizeof vis);
    vis[0]=vis[1]=false;
    for(int i=2;i<N;i++){
        if(vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<N;j+=i){
                vis[j]=false;
            }
        }
    }
}
void get_factor(int n){
    v.clear();
    for(int i=0;i<prime.size() && prime[i]<n;i++){
        if(n%prime[i]==0){
            int cnt=0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            v.push_back(P(prime[i],cnt));
        }
    }
    if(n!=1){
        v.push_back(P(n,1));
    }
}
int main(){
    init();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        get_factor(m);
        ans.clear();
        for(int i=1;i<=n-1;i++){
            // ( n - i ) / i
            int x=n-i,y=i;
            bool ok=true;
            for(int j=0;j<v.size();j++){
                int p=v[j].first;
                while(x%p==0){
                    x/=p;
                    v[j].second--;
                }
                while(y%p==0){
                    y/=p;
                    v[j].second++;
                }
                if(v[j].second>0){
                    ok=false;
                }
            }
            if(ok) ans.push_back(i+1);
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d",ans[i]);
            if(i+1==ans.size()) ;
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
