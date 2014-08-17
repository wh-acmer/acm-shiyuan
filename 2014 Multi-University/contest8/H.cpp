#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    LL x,k,cas=0;
    while(scanf("%I64d%I64d",&x,&k)!=EOF){
        if(x==0 && k==0) break;
        LL j=1; // j represent x/i
        for(int i=1;i<=k;i++){
            if(x%i==0){
                j=x/i;
            }
            else{
                if(j==x/i+1) // i/(i+1)对j没影响,j不再变化
                    break;
                j=x/i+1;
                x=j*i;
            }
        }
        printf("Case #%I64d: %I64d\n",++cas,k*j);
    }
    return 0;
}
