#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
#define N 30
char sa[N],sb[N];
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%s%s",&sa,&sb);
        LL aa=0,ab=0,ba=0,bb=0;
        int l=strlen(sa);
        for(int i=0;i<l;i++){
            int ok=1;
            for(int j=0;i+j<l;j++){
                if(sa[i+j]!=sa[j]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                aa|=1<<(l-1-i);
            }
        }
        for(int i=0;i<l;i++){
            int ok=1;
            for(int j=0;i+j<l;j++){
                if(sb[i+j]!=sb[j]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                bb|=1<<(l-1-i);
            }
        }
        for(int i=0;i<l;i++){
            int ok=1;
            for(int j=0;i+j<l;j++){
                if(sa[i+j]!=sb[j]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ab|=1<<(l-1-i);
            }
        }
        for(int i=0;i<l;i++){
            int ok=1;
            for(int j=0;i+j<l;j++){
                if(sb[i+j]!=sa[j]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                ba|=1<<(l-1-i);
            }
        }

        aa-=ab;
        bb-=ba;
        if(aa<0) aa*=-1;
        if(bb<0) bb*=-1;

        aa+=bb;
        LL g=gcd(aa,bb);
        aa/=g;
        bb/=g;
        printf("Case #%d:\n",cas);
        if(bb==0){
            printf("0\n");
        }
        else if(aa==1){
            printf("1\n");
        }
        else{
            printf("%I64d/%I64d\n",bb,aa);
        }
    }
    return 0;
}
