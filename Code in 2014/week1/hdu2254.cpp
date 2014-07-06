#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define N 1010
#define mod 2008
map<int,int>mp;
struct Matrix{
    int m[32][32];
}E,D,P[10010];
int now;
void init(){
    for(int i=1;i<32;i++){
        for(int j=1;j<32;j++){
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
        }
    }
}
Matrix multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<now;i++){
        for(int j=1;j<now;j++){
            ans.m[i][j]=0;
            for(int k=1;k<now;k++){
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
                ans.m[i][j]%=mod;
            }
        }
    }
    return ans;
}
int main(){
    int n,k,p1,p2,v1,v2,t1,t2;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        init();
        now=1;
        for(int i=0;i<n;i++){
            scanf("%d%d",&p1,&p2);
            if(!mp.count(p1)) mp[p1]=now++;
            if(!mp.count(p2)) mp[p2]=now++;
            D.m[mp[p1]][mp[p2]]++;
        }
        scanf("%d",&k);
        P[1]=D;
        for(int i=2;i<10010;i++){
            P[i]=multi(P[i-1],D);
        }
        while(k--){
            scanf("%d%d%d%d",&v1,&v2,&t1,&t2);
            if(t1>t2){
                swap(t1,t2);
            }
            if(!mp.count(v1) || !mp.count(v2)){
                printf("0\n");
            }
            else{
                int ans=0;
                for(int i=t1;i<=t2;i++){
                    ans+=P[i].m[mp[v1]][mp[v2]];
                    ans%=mod;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
