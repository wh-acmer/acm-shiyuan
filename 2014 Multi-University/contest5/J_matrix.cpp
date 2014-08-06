#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long LL;
#define N 810
#define mx 100000000
int E[N][N],D[N][N],C[N][N];
int pika[N][N];
int n;
void multi(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pika[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++){
            if(C[i][k]==0) continue;
            for(int j=1;j<=n;j++){
                pika[i][j]+=C[i][k]*D[k][j];
                if(pika[i][j]>mx)
                    pika[i][j]%=3;
            }
        }
}
int main(){
    int x;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&x);
                C[i][j]=x%3;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&x);
                D[i][j]=x%3;
            }
        }
        multi();
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++) printf("%d ",pika[i][j]%3);
            printf("%d\n",pika[i][n]%3);
        }
    }
    return 0;
}
