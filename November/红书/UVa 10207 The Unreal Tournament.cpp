/*
    Wrong Answer
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
#define eps (1e-6)
int main(){
    double p,q;
    int n;
    while(1){
        scanf("%lf%d",&p,&n);
        q=1-p;
        if(n==0) return 0;
        while(n--){
            int I,J;
            scanf("%d%d",&I,&J);
            double ans=0;
            double tmp=pow(p,I);
            for(int i=0;i<=J-1;i++){
                ans+=tmp;
                if(tmp<eps) break;
                tmp*=(I+i);
                tmp/=i+1;
                tmp*=q;
            }
            printf("%.5lf\n",ans+eps);
            int X=I+J;
            if(I<J) swap(I,J);
            ans=1;
            for(int i=I+J;i>J;i--){
                ans*=i;
                ans/=I-(I+J-i);
            }
            printf("%.lf\n",(ans-1)*2+eps);
        }
        printf("\n");
    }
    return 0;
}
