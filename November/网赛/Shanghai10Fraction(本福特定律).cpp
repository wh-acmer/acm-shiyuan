/*
    本福特定律： b进制中，以n为前缀的数字出现的概率为 logb(n+1)-logb(n)
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool ok(int n){
    while(n%10==0) n/=10;
    return n==1;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int n,b,q;
        scanf("%d%d%d",&n,&b,&q);
        double ans=log10(n+1.0)-log10(n+0.0);
        if(ok(q)){
            if(q!=1){
                while(b<n) b*=10;
            }
            while(b>n) b/=10;
            ans=(n==b)?1.0:0.0;
        }
        printf("Case #%d: %.5lf\n",cas,ans);
    }
    return 0;
}


/*
    暴力每组跑20w,求概率(去掉前几项)

*/
/*

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 2000000
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int n,b,q;
        scanf("%d%d%d",&n,&b,&q);
        double ln=log10(n+0.0);
        double lnn=log10(n+1.0);
        double st=log10(b+0.0);
        double add=log10(q+0.0);
        int shit=1000;
        int cycle=shit+N;
        int ans=0;
        while(cycle--){
            while(st>lnn) ln+=1,lnn+=1;
            if(shit){
                shit--;
            }
            else{
                if(st>=ln && st<lnn){
                    ans++;
                }
            }
            st+=add;
        }
        printf("Case #%d: %.5lf\n",cas,1.0*ans/N);
    }
    return 0;
}

*/
