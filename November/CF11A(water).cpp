// Increasing Sequence
// http://codeforces.com/problemset/problem/11/A
// water

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 2010
__int64 a[N];
int main(){
    __int64 n,d;
    while(scanf("%I64d%I64d",&n,&d)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
        }
        __int64 ans=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) ;
            else{
                __int64 now=(a[i-1]-a[i])/d+1;
                ans+=now;
                a[i]+=now*d;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
