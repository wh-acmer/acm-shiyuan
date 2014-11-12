// Caisa and Pylons
// http://codeforces.com/problemset/problem/463/B
// water

#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&x);
        int ans=x;
        while(n-->1){
            scanf("%d",&x);
            if(x>ans) ans=x;
        }
        printf("%d\n",ans);
    }
    return 0;
}
