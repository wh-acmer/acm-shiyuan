// Crossing Rivers
// http://uva.onlinejudge.org/external/122/12230.pdf
// water

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
int main(){
    int n,d,cas=0,ok=1;
    while(scanf("%d%d",&n,&d)!=EOF){
        if(n==0 && d==0) break;
        double ans=d,sum=0;
        while(n--){
            int p,l,v;
            scanf("%d%d%d",&p,&l,&v);
            ans+=2.0*l/v;
            ans-=l;
        }
        printf("Case %d: %.3lf\n\n",++cas,ans);
    }
    return 0;
}
