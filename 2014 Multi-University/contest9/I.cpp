#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int score,n;
        scanf("%d%d",&score,&n);
        int total=score*n;
        double mx=0,mi=4;
        for(int s1=0;s1<=n;s1++){
            for(int s2=0;s2+s1<=n;s2++){
                for(int s3=0;s3+s2+s1<=n;s3++){
                    for(int s4=0;s4+s3+s2+s1<=n;s4++){
                        int s5=n-s1-s2-s3-s4;
                        int l=85*s1+80*s2+75*s3+70*s4+60*s5;
                        int r=100*s1+84*s2+79*s3+74*s4+69*s5;
                        if(total>=l && total<=r){
                            double get=4.0*s1+3.5*s2+3.0*s3+2.5*s4+2.0*s5;
                            get/=n;
                            mx=max(mx,get);
                            mi=min(mi,get);
                        }
                    }
                }
            }
        }
        printf("%.4lf %.4lf\n",mi,mx);
    }
    return 0;
}
