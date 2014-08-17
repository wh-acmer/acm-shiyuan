#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    LL h,a,b,k,cas=0;
    while(scanf("%I64d%I64d%I64d%I64d",&h,&a,&b,&k)!=EOF){
        if(h==0 && a==0 && b==0 && k==0) break;
        int ok=0;
        if(h<=a) ok=1;
        LL attack=a-b;
        if(attack*k-b>0) ok=1;
        if(attack>0 && (h-a+attack-1)/attack<k) ok=1;
        printf("Case #%d: ",++cas);
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
