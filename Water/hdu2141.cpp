/*
    water
    正解目测是hash
    可以用set水过，三重for的代码会MLE
    改成预处理两重for，查询两重for+set自带的二分能过
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;
set<int>s;
#define maxn 501
int a[maxn],b[maxn],c[maxn];
int main(){
    int L,N,M,cas=1;
    while(scanf("%d%d%d",&L,&N,&M)!=EOF){
        s.clear();
        for(int i=0;i<L;i++) scanf("%d",&a[i]);
        for(int i=0;i<N;i++) scanf("%d",&b[i]);
        for(int i=0;i<M;i++) scanf("%d",&c[i]);
        for(int i=0;i<L;i++){
            for(int j=0;j<N;j++){
                    s.insert(a[i]+b[j]);
                }
            }
        printf("Case %d:\n",cas++);
        int S,X;
        scanf("%d",&S);
        while(S--){
            scanf("%d",&X);
            bool ok=false;
            for(int i=0;i<M;i++){
                if(s.count(X-c[i])){
                    ok=true;
                    break;
                }
            }
            if(ok) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
