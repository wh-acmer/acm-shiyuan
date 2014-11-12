// LCM Pair Sum
// http://codeforces.com/gym/100438/attachments/download/2448/20122013-southwestern-europe-regional-contest-swerc-12-en.pdf
// math

// AC
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#define N 16
int P[N],A[N];
const LL mod=1000000007;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1){
            b--;
            ans=(ans*a)%mod;
        }
        else{
            b>>=1;
            a=(a*a)%mod;
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int C;
        scanf("%d",&C);
        LL num=1,ans=1;
        for(int i=0;i<C;i++){
            scanf("%d%d",&P[i],&A[i]);
            num=(num*Pow(P[i],A[i]))%mod;
            LL tmp=(Pow(P[i],A[i]+1)+mod-1)%mod;
            tmp*=Pow(P[i]-1,mod-2);
            tmp%=mod;
            tmp+=Pow(P[i],A[i])*A[i];
            tmp%=mod;
            ans*=tmp;
            ans%=mod;
        }
        ans=(ans+num)%mod;
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}


/*

TLE

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#define N 16
int P[N],A[N];
const LL mod=1000000007;
LL dp[1001][60];
LL get_mod(LL n){
    if(n>=mod) return n-n/mod*mod;
    return n;
}
LL Pow(LL a,LL b){
    if(a<1001 && b<60 && dp[a][b]!=-1){
        return dp[a][b];
    }
    LL ans=1;
    while(b){
        if(b&1){
            b--;
            ans=get_mod(ans*a);
        }
        else{
            b>>=1;
            a=get_mod(a*a);
        }
    }
    if(a<1001 && b<60){
        dp[a][b]=ans;
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof dp);
    for(int cas=1;cas<=T;cas++){
        int C;
        scanf("%d",&C);
        LL num=1;
        for(int i=0;i<C;i++){
            scanf("%d%d",&P[i],&A[i]);
            num=get_mod(num*Pow(P[i],A[i]));
        }
        int all=(1<<C);
        LL ans=0,aans=0;
        for(int state=0;state<all;state++){
            LL x=1,y=1,s=state,count=1;
            LL shit=1,shit_count=1;
            for(int i=0;i<C;i++){
                if(s&1){
                    x=get_mod(x*Pow(P[i],A[i]));
                    y=get_mod(get_mod(get_mod(Pow(P[i],A[i]+1)+mod-1)*Pow(P[i]-1,mod-2))*y);
                    count=get_mod((A[i]+1)*count);
                    shit=get_mod(shit*(1+Pow(P[i],A[i])));
                    shit_count=get_mod(shit_count*2);
                }
                else{
                    y=get_mod(y*Pow(P[i],A[i]));
                    shit=get_mod(shit*Pow(P[i],A[i]));
                }
                s>>=1;
            }
            ans=get_mod(x*count+y+ans);
            aans=get_mod(x*shit_count+shit+aans);
        }
        aans=get_mod(aans*Pow(2,mod-2));
        ans=(ans-aans+num+mod)%mod;
        printf("Case %d: %I64d\n",cas,ans);
    }
    return 0;
}


*/
