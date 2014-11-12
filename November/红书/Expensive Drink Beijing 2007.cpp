/*
    Wrong Answer
*/
#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-5;
const double inf = 1e20;

#define OPTIMAL -1          //表示有唯一的最优基本可行解
#define UNBOUNDED -2        //表示目标函数的最大值无边界
#define FEASIBLE -3         //表示有可行解
#define INFEASIBLE -4       //表示无解
#define PIVOT_OK 1          //还可以松弛
#define maxn 1000

struct LinearProgramming{
    int basic[maxn], row[maxn], col[maxn];
    double c0[maxn];

    double dcmp(double x){
        if (x > eps)    return 1;
        else if (x < -eps)   return -1;
        return 0;
    }
    void init(int n, int m, double c[], double a[maxn][maxn], double rhs[], double &ans) { //初始化
        for(int i = 0; i <= n+m; i++) {
            for(int j = 0; j <= n+m; j++)   a[i][j]=0;
            basic[i]=0; row[i]=0; col[i]=0;
            c[i]=0; rhs[i]=0;
        }
        ans=0;
    }
    int Pivot(int n, int m, double c[], double a[maxn][maxn], double rhs[], int &i, int &j){
        double min = inf;
        int k = -1;
        for (j = 0; j <= n; j ++)
            if (!basic[j] && dcmp(c[j]) > 0)
                if (k < 0 || dcmp(c[j] - c[k]) > 0)     k = j;
        j = k;
        if (k < 0)  return OPTIMAL;
        for (k = -1, i = 1; i <= m; i ++)   if (dcmp(a[i][j]) > 0)
            if (dcmp(rhs[i] / a[i][j] - min) < 0){  min = rhs[i]/a[i][j]; k = i;  }
        i = k;
        if (k < 0)  return UNBOUNDED;
        else    return PIVOT_OK;
    }
    int PhaseII(int n, int m, double c[], double a[maxn][maxn], double rhs[], double &ans, int PivotIndex){
        int i, j, k, l; double tmp;
        while(k = Pivot(n, m, c, a, rhs, i, j), k == PIVOT_OK || PivotIndex){
            if (PivotIndex){    i = PivotIndex; j = PivotIndex = 0; }
            basic[row[i]] = 0;  col[row[i]] = 0;    basic[j] = 1;   col[j] = i;     row[i] = j;
            tmp = a[i][j];
            for (k = 0; k <= n; k ++)   a[i][k] /= tmp;
            rhs[i] /= tmp;
            for (k = 1; k <= m; k ++)
                if (k != i && dcmp(a[k][j])){
                    tmp = -a[k][j];
                    for (l = 0; l <= n; l ++)   a[k][l] +=  tmp*a[i][l];
                    rhs[k] += tmp*rhs[i];
                }
            tmp = -c[j];
            for (l = 0; l <= n; l ++)   c[l] += a[i][l]*tmp;
            ans -= tmp * rhs[i];
        }
        return k;
    }
    int PhaseI(int n, int m, double c[], double a[maxn][maxn], double rhs[], double &ans){
        int i, j, k = -1;
        double tmp, min = 0, ans0 = 0;
        for (i = 1; i <= m; i ++)
            if (dcmp(rhs[i]-min) < 0){min = rhs[i]; k = i;}
        if (k < 0)  return FEASIBLE;
        for (i = 1; i <= m; i ++)   a[i][0] = -1;
        for (j = 1; j <= n; j ++)   c0[j] = 0;
        c0[0] = -1;
        PhaseII(n, m, c0, a, rhs, ans0, k);
        if (dcmp(ans0) < 0) return INFEASIBLE;
        for (i = 1; i <= m; i ++)   a[i][0] = 0;
        for (j = 1; j <= n; j ++)
            if (dcmp(c[j]) && basic[j]){
                tmp = c[j];
                ans += rhs[col[j]] * tmp;
                for (i = 0; i <= n; i ++)   c[i] -= tmp*a[col[j]][i];
            }
        return FEASIBLE;
    }
    int simplex(int n, int m, double c[], double a[maxn][maxn], double rhs[], double &ans, double x[]){
        int i, j, k;
        for (i = 1; i <= m; i ++){
            for (j = n+1; j <= n+m; j ++)   a[i][j] = 0;
            a[i][n+i] = 1;  a[i][0] = 0;
            row[i] = n+i;   col[n+i] = i;
        }
        k = PhaseI(n+m, m, c, a, rhs, ans);
        if (k == INFEASIBLE)    return k;
        k = PhaseII(n+m, m, c, a, rhs, ans, 0);
        for (j = 0; j <= n+m; j ++) x[j] = 0;
        for (i = 1; i <= m; i ++)   x[row[i]] = rhs[i];
        return k;
    }
}ps;
double c[maxn],ans, a[maxn][maxn], b[maxn], x[maxn];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cas=0;
    double L,R;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%lf%lf",&L,&R);
        if(L>R) swap(L,R);
        ps.init(3,2*n+2,c,a,b,ans);
        for(int i=1;i<=n;i++){
            double a1,a2,a3,p;
            scanf("%lf%lf%lf%lf",&a1,&a2,&a3,&p);
            a[i*2-1][1]=a1;
            a[i*2-1][2]=a2;
            a[i*2-1][3]=a3;
            b[i*2-1]=p-L;

            a[i*2][1]=-a1;
            a[i*2][2]=-a2;
            a[i*2][3]=-a3;
            b[i*2]=R-p;

        }
        a[2*n+1][1]=1.0,a[2*n+1][2]=-1.0,a[2*n+1][3]=0.0;
        b[2*n+1]=0.0;

        a[2*n+2][1]=0.0,a[2*n+2][2]=1.0,a[2*n+2][3]=-1.0;
        b[2*n+2]=0.0;


        scanf("%lf%lf%lf",&c[1],&c[2],&c[3]);
        int tag=ps.simplex(3,2*n+2,c,a,b,ans,x);

        printf("Case %d: ",++cas);
        if(tag==-4){
            printf("Inconsistent data\n");
        }
        else if(tag==-2){
            printf("Too expensive!\n");
        }
        else if(tag==-1 || tag==-3){
            printf("%.4lf\n",ans+R+eps);
        }
        else{
            printf("Inconsistent data\n");
        }
    }
    return 0;
}
