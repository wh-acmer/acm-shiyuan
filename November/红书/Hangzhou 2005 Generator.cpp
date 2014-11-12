#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
char s[15];
int n;
LL Pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) b--,ans*=a;
        else b>>=1,a*=a;
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%s",&n,&s);
        int l=strlen(s);
        LL ans=0;
        for(int i=0;i<l;i++){
            int ok=1;
            for(int j=0;i+j<l;j++){
                if(s[j]!=s[i+j]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ans+=Pow(n,l-i);
            }
        }
        printf("Case %d:\n%lld\n",cas,ans);
        if(cas!=T) printf("\n");
    }
    return 0;
}
