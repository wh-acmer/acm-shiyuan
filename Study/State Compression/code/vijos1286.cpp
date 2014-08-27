#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int row,col,K;
vector<int>v,vt;
LL dp[2][1<<9][21];
int get(int x){
    int ans=0;
    while(x){
        if(x&1) ans++;
        x>>=1;
    }
    return ans;
}
void init(){
    v.clear(),vt.clear();
    for(int i=0;i<(1<<col);i++){
        if((i&(i>>1))==0 && (i&(i<<1))==0){
            v.push_back(i);
            vt.push_back(get(i));
        }
    }
}
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    while(scanf("%d%d%d",&row,&col,&K)!=EOF){
        if(row<col){
            swap(row,col);
        }
        init();
        memset(dp,0,sizeof dp);
        dp[0][0][0]=1;
        int now=1;
        for(int i=1;i<=row;i++){
            memset(dp[now],0,sizeof dp[now]);
            for(int j=0;j<v.size();j++){
                for(int k=0;k<v.size();k++){
                    if((v[j]&v[k])==0){
                        for(int x=vt[j];x<=K;x++)
                            dp[now][j][x]+=dp[now^1][k][x-vt[j]];
                    }
                }
            }
            now^=1;
        }
        LL ans=0;
        for(int i=0;i<v.size();i++){
            ans+=dp[now^1][i][K];
        }
        if(ans==0){
            printf("Impossible!\n");
            continue;
        }
        vector<int>tp;
        tp.clear();
        for(int i=row*col;i>row*col-K;i--){
            LL tmp=gcd(ans,i);
            ans/=tmp;
            tp.push_back(i/tmp);
        }
        for(int i=1;i<=K;i++){
            LL tmp=i;
            for(int j=0;j<tp.size();j++){
                LL ttmp=gcd(tmp,tp[j]);
                if(ttmp!=1){
                    tmp/=ttmp;
                    tp[j]/=ttmp;
                }
            }
            ans*=tmp;
        }
        LL aans=1;
        for(int i=0;i<tp.size();i++){
            aans*=tp[i];
        }
        printf("%lld/%lld\n",aans,ans);
    }
    return 0;
}
