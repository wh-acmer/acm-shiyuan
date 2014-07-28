#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
#define maxn 100010
LL mp[maxn];
const LL mod=1000000009;
LL Pow(LL a,LL b,LL c){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=(ans*a)%c;
        else b>>=1,a=(a*a)%c;
    }
    return ans;
}
LL inverce(LL a){
    return Pow(a,mod-2,mod);
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int l=0,r=0,ll,rr,x; memset(mp,0,sizeof(mp));
        while(n--){
            scanf("%d",&x);
            if(l-x>=0){
                ll=l-x;
            }
            else if(r-x>=0){
                if((l-x)&1) ll=1;
                else ll=0;
            }
            else{
                ll=x-r;
            }
            if(r+x<=m){
                rr=r+x;
            }
            else if(l+x<=m){
                if((r+x-m)&1) rr=m-1;
                else rr=m;
            }
            else{
                rr=m-(x-(m-l));
            }
            l=ll,r=rr;
        }
        LL ans=0; mp[0]=1;
        if(l==0) ans++;
        for(int i=1;i<=r;i++){
            if(m-i<i) mp[i]=mp[m-i];
            else mp[i]=(mp[i-1]*(m-i+1)%mod)*inverce(i)%mod;
            if(i>=l && i<=r && !((i-l)&1)) ans+=mp[i],ans%=mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
