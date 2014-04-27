#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int k; scanf("%d",&k);
        if(k<0) k*=-1;
        if(k==0){
            printf("3\n");
        }
        else{
            int n=0;
            int tmp=0;
            while(1){
                if((tmp-k)>=0 && (tmp-k)%2==0) break;
                n++;
                tmp+=n;
            }
            printf("%d\n",n);
        }
        if(T) printf("\n");
    }
    return 0;
}
