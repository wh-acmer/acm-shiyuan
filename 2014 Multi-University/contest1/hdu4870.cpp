#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
#define eps 1e-12
const int MAXN=235;
double a[MAXN][MAXN],x[MAXN];
int equ=229,var=229;
int Gauss(){
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++){
        max_r=k;
        for(i=k+1;i<equ;i++)
          if(fabs(a[i][col])>fabs(a[max_r][col]))
            max_r=i;
        if(fabs(a[max_r][col])<eps)return 0;
        if(k!=max_r){
            for(j=col;j<var;j++)
              swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0;i<equ;i++)
          if(i!=k){
              x[i]-=x[k]*a[i][k];
              for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
              a[i][col]=0;
          }
    }
    return 1;
}
int get_index(int x,int y){
    int ans=0,now=21;
    for(int i=0;i<x;i++){
        ans+=now-i;
    }
    ans+=y-x;
    return ans;
}
int main(){
    double p;
    while(scanf("%lf",&p)!=EOF){
        memset(a,0,sizeof(a));
        for(int i=0;i<20;i++){
            for(int j=i;j<21;j++){
                int index=get_index(i,j);
                a[index][index]=1;
                // win
                int x,y;
                if(i==j){
                    x=i,y=j+1;
                }
                else{
                    x=i+1,y=j;
                }
                x=max(0,x);
                y=min(y,20);
                int shit;
                shit=get_index(x,y);
                a[index][shit]-=p;
                // lose
                x=i-2,y=j;
                x=max(0,x);
                y=min(20,y);
                shit=get_index(x,y);
                a[index][shit]+=p-1;
            }
        }
        memset(x,0,sizeof(x));
        for(int i=0;i<230;i++){
            x[i]=1.0;
        }
        Gauss();
        double ans=x[0];
        printf("%.12lf\n",ans);
    }
    return 0;
}
