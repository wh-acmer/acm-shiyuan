#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int a[15];
struct Matrix{
    double m[2][2];
}E,D;
int n;
double p;
void init(){
    memset(E.m,0,sizeof(E.m));
    for(int i=0;i<2;i++){
        E.m[i][i]=1;
    }
    memset(D.m,0,sizeof(D.m));
    D.m[0][0]=p; D.m[0][1]=1-p;
    D.m[1][0]=1;
}
Matrix Multi(Matrix A,Matrix B){
    Matrix ans;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans.m[i][j]=0;
            for(int k=0;k<2;k++){
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
            }
        }
    }
    return ans;
}
Matrix Pow(Matrix A,int k){
    Matrix ans=E;
    while(k){
        if(k&1){
            k--;
            ans=Multi(ans,A);
        }
        else{
            k>>=1;
            A=Multi(A,A);
        }
    }
    return ans;
}
int main(){
    while(scanf("%d%lf",&n,&p)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        if(a[1]==1){
            printf("%.7f\n",0.0);
            continue;
        }
        init();
        Matrix tmp;
        tmp.m[0][0]=1;
        tmp.m[1][0]=0;
        int now=1;
        for(int i=1;i<=n;i++){
            int pre=a[i]-1;
            tmp=Multi(Pow(D,pre-now),tmp);
            now=a[i];
            tmp.m[1][0]=tmp.m[0][0];
            tmp.m[0][0]=0;
        }
        printf("%.7f\n",tmp.m[1][0]*(1-p));
    }
    return 0;
}
