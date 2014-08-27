#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
vector<int>v,vt;
int row,col;
int a[101],x;
char s[12];
int dp[2][61][61];
int get(int i){
    int ans=0;
    while(i){
        if(i&1) ans++;
        i>>=1;
    }
    return ans;
}
void init(){
    v.clear();
    vt.clear();
    for(int i=0;i<(1<<col);i++){
        if((i&(i>>1))==0 && (i&(i<<1))==0 && (i&(i>>2))==0 && (i&(i<<2))==0 ){
            v.push_back(i);
            vt.push_back(get(i));
        }
    }
}
int main(){
    while(scanf("%d%d",&row,&col)!=EOF){
        init();
        memset(a,0,sizeof a);
        for(int i=1;i<=row;i++){
            scanf("%s",&s);
            for(int j=0;j<col;j++){
                if(s[j]=='P'){
                    a[i]|=(1<<j);
                }
            }
        }
        dp[0][0][0]=1;
        int ans=0;
        int now=1;
        for(int i=1;i<=row;i++){
            for(int j=0;j<v.size();j++){
                if((a[i]&v[j])==v[j]){
                    for(int k=0;k<v.size();k++){
                        if((a[i-1]&v[k])==v[k] && (v[k]&v[j])==0){
                            int tmp=0;
                            if(i>1){
                                for(int l=0;l<v.size();l++){
                                    if((v[l]&a[i-2])==v[l] && (v[l]&v[j])==0 && (v[l]&v[k])==0){
                                        tmp=max(tmp,dp[now^1][k][l]);
                                    }
                                }
                            }
                            dp[now][j][k]=tmp+vt[j];
                            ans=max(ans,dp[now][j][k]);
                        }
                    }
                }
            }
            now^=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
