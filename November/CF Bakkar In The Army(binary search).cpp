// Bakkar In The Army
// http://codeforces.com/gym/100283/problem/F

#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
LL get(LL n){
    return (n*(n+1)/2)*(2*n+1)/3;
}
LL solve(LL n){
    LL l=1,r=2000000,mid,ans=1;
    while(l<=r){
        mid=(l+r)>>1;
        if(get(mid)<=n){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main(){
    int T;
    freopen("army.in","r",stdin);
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        LL n;
        cin>>n;
        LL ceng=solve(n);
        LL ans=ceng*ceng;
        LL re=n-get(ceng);
        LL now=ceng+1;
        //cout<<ceng<<":"<<re<<endl;
        if(re==0){
            printf("Case %d: %I64d\n",cas,ans);
            continue;
        }
        if((1+now)*now/2>=re){
            LL l=1,r=now,mid,Ans=1;
            while(l<=r){
                mid=(l+r)>>1;
                LL pre=(1+mid)*mid/2;
                if(pre<=re){
                    Ans=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            re-=(1+Ans)*Ans/2;
            ans+=Ans+(re!=0);
        }
        else{
            re-=(1+now)*now/2;
            ans+=now;
            LL l=1,r=now-1,mid,Ans=1;
            while(l<=r){
                mid=(l+r)>>1;
                LL pre=(now-1+mid)*(now-1-mid+1)/2;
                if(pre>=re){
                    Ans=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            re-=(now-1+Ans)*(now-1-Ans+1)/2;
            ans+=(now-1-Ans+1);
        }
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}
