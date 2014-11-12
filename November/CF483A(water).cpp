// Counterexample
// http://codeforces.com/problemset/problem/483/A
// brute force

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    LL a,b;
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        bool ok=true;
        for(LL i=a;ok&&i<=b;i++){
            for(LL j=i+1;ok&&j<=b;j++){
                for(LL k=j+1;ok&&k<=b;k++){
                    if(gcd(i,j)==1 && gcd(j,k)==1 && gcd(i,k)!=1){
                        printf("%I64d %I64d %I64d\n",i,j,k);
                        ok=false;
                    }
                }
            }
        }
        if(ok) printf("-1\n");
    }
    return 0;
}
