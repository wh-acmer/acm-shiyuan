// Design Tutorial: Learn from Math
// http://codeforces.com/problemset/problem/472/A
// water

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
#define N 1000010
bool vis[N];
vector<int>v;
void init(){
    memset(vis,true,sizeof vis);
    for(int i=2;i<N;i++){
        if(vis[i]){
            for(int j=2*i;j<N;j+=i){
                vis[j]=false;
            }
        }
    }
    v.clear();
    for(int i=4;i<N;i++){
        if(!vis[i]){
            v.push_back(i);
        }
    }
}
int main(){
    int n;
    init();
    while(scanf("%d",&n)!=EOF){
        for(int i=0;v[i]<n;i++){
            if(!vis[n-v[i]]){
                printf("%d %d\n",v[i],n-v[i]);
                break;
            }
        }
    }
    return 0;
}
