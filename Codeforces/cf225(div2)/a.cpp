#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1010
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(n*n+1)/2);
    for(int i=0;i<n;i++){
        if(i&1){
            for(int j=0;j<n;j++){
                if(j&1) printf("C");
                else printf(".");
            }
            printf("\n");
        }
        else{
            for(int j=0;j<n;j++){
                if(j&1) printf(".");
                else printf("C");
            }
            printf("\n");
        }
    }
    return 0;
}
