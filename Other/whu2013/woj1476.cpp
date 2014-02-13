/*
    sg game

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;
#define N 1005
int sg[2*N];
set<int>s;//±ÿ∞‹Ã¨
int solve(){
    int i=0;
    while(s.count(i)) i++;
    return i;
}
int main(){
    sg[0]=0;sg[1]=0;
    for(int i=2;i<N;i++){
        s.clear();
        for(int j=1;j<i;j++){
            s.insert(sg[j-1]^sg[i-j-1]);
        }
        sg[i]=solve();
    }
    int T,x,y,c,cas=0;
    scanf("%d",&T);
    while(T--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            x=0,y=0;
            for(int j=1;j<=n;j++){
                scanf("%d",&c);
                if(c==1){
                    if(j&1) ans^=sg[x],x=0;
                    else ans^=sg[y],y=0;
                }
                else{
                    if(j&1){
                        x++;
                        if(j==n || j==n-1) ans^=sg[x];
                    }
                    else{
                        y++;
                        if(j==n || j==n-1) ans^=sg[y];
                    }
                }
            }
        }
        printf("Case %d: ",++cas);
        if(ans) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
