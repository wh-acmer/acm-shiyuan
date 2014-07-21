#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 560
int d[3];
double p[maxn],e1[maxn],e2[maxn];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
       int n,a,b,c;
       scanf("%d",&n);
       for(int i=0;i<3;i++){
            scanf("%d",&d[i]);
       }
       scanf("%d%d%d",&a,&b,&c);
       memset(p,0,sizeof(p));
       double pp=1.0/d[0]/d[1]/d[2];
       for(int i=1;i<=d[0];i++){
            for(int j=1;j<=d[1];j++){
                for(int k=1;k<=d[2];k++){
                    if(i==a && j==b && k==c) ;
                    else{
                        p[i+j+k]+=pp;
                    }
                }
            }
       }
       memset(e1,0,sizeof(e1));
       memset(e2,0,sizeof(e2));
       for(int i=n;i>=0;i--){
            for(int j=3;j<=d[0]+d[1]+d[2];j++){
                e1[i]+=e1[i+j]*p[j];
                e2[i]+=e2[i+j]*p[j];
            }
            e1[i]+=1;
            e2[i]+=pp;
       }
       printf("%.9lf\n",e1[0]/(1-e2[0]));
    }
    return 0;
}
