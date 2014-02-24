#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
vector<P>v,vt;
map<int,int>mp;
map<int,int>::iterator it;
vector<int>pt;
LL tmp;
int n,A,B,mi;
void init(){
    v.clear(); v.push_back(P(0,1));
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;i++){
        vt.clear(); scanf("%d",&mi);
        for(int j=0;j<v.size();j++){
            vt.push_back(v[j]);
            vt.push_back(P(v[j].first+mi+1,-v[j].second));
        }
        v.assign(vt.begin(),vt.end());
    }
    mp.clear();
    for(int i=0;i<v.size();i++)
        mp[v[i].first]+=v[i].second;
}
int gcd(int a,int b){
    if(b==0) return a; return gcd(b,a%b);
}
LL solve(int x){
    LL ans=0;
    for(it = mp.begin();it!=mp.end();it++){
        tmp=1;
        if(x<it->first) continue;

        pt.clear();
        for(int i=1;i<=n;i++)
            pt.push_back(n+x-it->first+1-i);
        for(int i=1;i<=n;i++){
            int now=i;
            while(now!=1){
                for(int j=0;j<pt.size()&&now!=1;j++){
                    mi=gcd(pt[j],now);
                    now/=mi,pt[j]/=mi;
                }
            }
        }
        for(int i=0;i<pt.size();i++) tmp=(tmp*pt[i])%2004;
        ans=(ans+it->second*tmp)%2004;
    }
    return ans;
}
int main(){
    init();
    printf("%lld\n",((solve(B)-solve(A-1))%2004+2004)%2004);
    return 0;
}

