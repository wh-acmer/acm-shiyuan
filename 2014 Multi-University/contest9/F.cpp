#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 1010
int a[N][N],b[N][N],c[N][N];
struct Matrix{
    int m[6][6];
}D,E;
int n,K;
void init(){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            E.m[i][j]=(i==j);
        }
    }
}
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            ans.m[i][j]=0;
            for(int k=0;k<K;k++){
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%6;
            }
        }
    }
    return ans;
}
Matrix Pow(Matrix A,LL k){
    Matrix ans=E;
    while(k){
        if(k&1) k--,ans=Multi(ans,A);
        else k>>=1,A=Multi(A,A);
    }
    return ans;
}
int main(){
    init();
    while(scanf("%d%d",&n,&K)!=EOF){
        if(n==0 && K==0) break;
        Matrix tmp;
        for(int i=0;i<n;i++){
            for(int j=0;j<K;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<K;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&b[i][j]);
            }
        }
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                tmp.m[i][j]=0;
                for(int k=0;k<n;k++){
                    tmp.m[i][j]+=b[i][k]*a[k][j];
                    tmp.m[i][j]%=6;
                }
            }
        }
        tmp=Pow(tmp,n*n-1);
        memset(c,0,sizeof c);
        for(int i=0;i<n;i++){
            for(int j=0;j<K;j++){
                for(int k=0;k<K;k++){
                    c[i][j]+=a[i][k]*tmp.m[k][j];
                    c[i][j]%=6;
                }
            }
        }
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<K;k++){
                    a[i][j]+=c[i][k]*b[k][j];
                    a[i][j]%=6;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=a[i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
