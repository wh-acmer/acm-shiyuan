#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans=ans*a;
        else b/=2,a=a*a;
    }
    return ans;
}
int main(){
    LL p,d;
    while(scanf("%I64d%I64d",&p,&d)!=EOF){
        LL ans=p;
        int init=0;
        while(ans%10==9) ans/=10,init++;
        int ansx=0;
        for(int i=1;i<=18;i++){
            LL cnt=p%Pow(10,i)+1;
            if(cnt<=d) if(p-cnt>=0) ans=p-cnt,ansx=i;
        }
        if(ansx<=init) ans=p; // 因为这个WA在第93组数据上了
        printf("%I64d\n",ans);
    }
    return 0;
}
