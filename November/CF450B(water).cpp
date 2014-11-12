// Jzzhu and Sequences
// http://codeforces.com/problemset/problem/450/B
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mod=1000000007;
int main(){
    int x,y,n;
    while(scanf("%d%d%d",&x,&y,&n)!=EOF){
        n%=6;
        int ans;
        if(n==1) ans=x;
        else if(n==2) ans=y;
        else if(n==3) ans=y-x;
        else if(n==4) ans=-x;
        else if(n==5) ans=-y;
        else ans=x-y;
        ans%=mod;
        ans+=mod;
        ans%=mod;
        printf("%d\n",ans);
    }
    return 0;
}
