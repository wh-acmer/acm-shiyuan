/*
    water
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
bool ok(long long n){
    if(n%8==0)  return true;
    int tmp=n,sum1=0,sum2=0;
    while(tmp){
        sum1+=tmp%10;
        sum2+=(tmp%10)*(tmp%10);
        tmp/=10;
    }
    if(sum1%8==0) return true;
    if(sum2%8==0) return true;
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long n;
        scanf("%I64d",&n);
        if(ok(n)) printf("Lucky number!\n");
        else printf("What a pity!\n");
    }
    return 0;
}
