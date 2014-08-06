#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
#define N 801
bitset<N>A[2][N],B[2][N];
int main(){
    int n,x,add;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                A[i][j].reset();
                B[i][j].reset();
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&x);
                x%=3;
                if(x){
                    x--;
                    A[x][i].set(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&x);
                x%=3;
                if(x){
                    x--;
                    B[x][j].set(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x=0;
                for(int _i=0;_i<2;_i++){
                    for(int _j=0;_j<2;_j++){
                        add=2-(_i==_j);
                        x+=(A[_i][i] & B[_j][j]).count()*add;
                    }
                }
                if(j==n-1) printf("%d\n",x%3);
                else printf("%d ",x%3);
            }
        }
    }
    return 0;
}
