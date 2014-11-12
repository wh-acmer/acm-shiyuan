// Diverse Permutation
// http://codeforces.com/contest/483/problem/C
// constructive algorithm

#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        int now=1;
        int tag=1;
        printf("%d ",now);
        int count=k;
        while(count--){
            now+=tag*(count+1);
            tag*=-1;
            printf("%d ",now);
        }
        k+=2;
        while(k<=n){
            printf("%d ",k++);
        }
        printf("\n");
    }
    return 0;
}
