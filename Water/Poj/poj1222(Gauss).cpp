#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 31;
int equ,var;/// equ个方程，var个变量
int a[maxn][maxn];
int x[maxn];///解
bool free_x[maxn];///不确定变元
int free_num;
int gauss()
{
    int i,j,k;
    int max_r;
    int col=0;
    int ta,tb;
    int LCM;
    int tmp;
    int free_x_num;
    int free_index;
    for(k=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
        {
            if(abs(a[i][col])>abs(a[max_r][col]))
                max_r=i;
        }
        if(max_r!=k)
        {
            for(j=k;j<var+1;j++)
                swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
        {
            if(a[i][col]!=0)
            {
                /*
                LCM=lcm(abs(a[i][col]),abs(a[k][col]));
                ta=LCM/abs(a[i][col]);
                tb=LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0)
                    tb=-tb;  */
                for(j=col;j<var+1;j++)
                    a[i][j]^=a[k][j];
                    //a[i][j]=a[i][j]*ta-a[k][j]*tb;
            }
        }
    }

    // 无解和无穷解的情况不会出现，30个变元，30个方程组，一定有解
    /*for(i=k;i<equ;i++)
        if(a[i][col]!=0)
            return -1; /// 无解
    if(k<var) /// 无穷解
    {
        for(i=k-1;i>=0;i--)
        {
            free_x_num=0;
            for(j=0;j<var;j++)
            {
                if(a[i][j]!=0&&free_x[j])
                {
                    free_x_num++;
                    free_index=j;
                }
            }
            if(free_x_num>1)
                continue;
            tmp=a[i][var];
            for(j=0;j<var;j++)
            {
                if(a[i][j]!=0&&j!=free_index)
                    tmp-=a[i][j]*x[j];
            }
            x[free_index]=tmp/a[i][free_index];
            free_x[free_index]=0;
        }
        return var-k;
    } */

    for(i=var-1;i>=0;i--)
    {
        x[i]=a[i][var];
        for(j=i+1;j<var;j++)
            x[i]^=(a[i][j]&&x[j]);
            /*if(a[i][j]!=0)
                tmp-=a[i][j]*x[j];  */

        /*if(tmp%a[i][i]!=0)
            return -2;
        x[i]=tmp/a[i][i];  */
    }
    return 0;
}
int main()
{
    equ=30;
    var=30;
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<30;i++)
            scanf("%d",&a[i][30]);
        for(int i=0;i<5;i++)
        for(int j=0;j<6;j++)
        {
            int cnt=6*i+j;
            a[cnt][cnt]=1;
            if(i>0)
                a[cnt-6][cnt]=1;
            if(i<4)
                a[cnt+6][cnt]=1;
            if(j>0)
                a[cnt-1][cnt]=1;
            if(j<5)
                a[cnt+1][cnt]=1;
        }
        gauss();
        printf("PUZZLE #%d\n",cases);
        for(int i=0;i<30;i++)
        {
            if(i%6==5)
                printf("%d\n",x[i]);
            else
                printf("%d ",x[i]);
        }
    }
    return 0;
}
