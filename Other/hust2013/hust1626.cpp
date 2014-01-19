/*
    题意：长度为n的绳子切成m段，求最小段的期望
    思路：枚举最小段为1到n/m的情况，用隔板法放剩下的绳子
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        double ans=0;
        for(int i=1;i<=(n/m);i++){
            double tmp=1;
            for(int j=1;j<=m-1;j++){
                tmp*=(n-i*m+m-j)/(n-j+0.0);
            }
            ans+=tmp;
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}
