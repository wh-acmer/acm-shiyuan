// Fixed Points
// http://codeforces.com/problemset/problem/347/B
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100010
int a[N];
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            a[x]=i;
            if(a[x]==x){
                ans++;
            }
        }
        int mx=0;
        for(int i=1;i<n;i++){
            if(a[a[i]]==i && a[i]!=i){
                mx=max(mx,2);
            }
            else if(a[i]!=i){
                mx=max(mx,1);
            }
        }
        ans+=mx;
        printf("%d\n",ans);
    }
    return 0;
}
