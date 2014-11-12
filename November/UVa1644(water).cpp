// Prime Gap
// http://uva.onlinejudge.org/external/16/1644.pdf
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 1299709
bool vis[N+10];
vector<int>v;
void init(){
    v.clear();
    memset(vis,true,sizeof vis);
    vis[0]=vis[1]=false;
    for(int i=2;i<N+10;i++){
        if(vis[i]){
            v.push_back(i);
            for(int j=2*i;j<N+10;j+=i){
                vis[j]=false;
            }
        }
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)&&n){
        if(vis[n]) printf("0\n");
        else{
            int index=upper_bound(v.begin(),v.end(),n)-v.begin();
            int ans=v[index];
            index--;
            printf("%d\n",ans-v[index]);
        }
    }
    return 0;
}
