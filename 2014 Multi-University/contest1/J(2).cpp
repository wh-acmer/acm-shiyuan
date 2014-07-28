#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
#define eps 1e-12
const int MAXN=22;
double a[MAXN][MAXN],x[MAXN];
int equ=21,var=21;
int Gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
          if(fabs(a[i][col])>fabs(a[max_r][col]))
            max_r=i;
        if(fabs(a[max_r][col])<eps)return 0;
        if(k!=max_r)
        {
            for(j=col;j<var;j++)
              swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0;i<equ;i++)
          if(i!=k)
          {
              x[i]-=x[k]*a[i][k];
              for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
              a[i][col]=0;
          }
    }
    return 1;
}
int main(){
    double p;
    while(scanf("%lf",&p)!=EOF){
        memset(a,0,sizeof(a));
        for(int i=0;i<20;i++){
            a[i][i]=1;
            if(i+1<=20) a[i][i+1]=-p;
            if(i-2>=0) a[i][i-2]=p-1;
        }
        a[0][0]=p,a[1][0]=p-1;  a[20][20]=1;
        for(int i=0;i<20;i++) x[i]=1; x[20]=0;
        double ans=0;
        if(Gauss()){
            ans=x[0]*2-x[19];
        }
        printf("%.12lf\n",ans);
    }
    return 0;
}
