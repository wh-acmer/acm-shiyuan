#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 8010
LL f[N],g[N];
int main(){
    int num1,num2,num3;
    while(scanf("%d%d%d",&num1,&num2,&num3)!=EOF){
        if(num1==0 && num2==num1 && num3==num2) break;
        memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
        for(int i=0;i<=num1;i++)  f[i]=1;
        for(int j=0;j<N;j++){
            for(int k=0;k+j<N&&k<=2*num2;k+=2)
                g[j+k]+=f[j];
        }
        memcpy(f,g,sizeof(g));
        memset(g,0,sizeof(g));
        for(int j=0;j<N;j++){
            for(int k=0;k+j<N&&k<=5*num3;k+=5)
                g[j+k]+=f[j];
        }
        for(int i=1;;i++){
            if(g[i]==0){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
