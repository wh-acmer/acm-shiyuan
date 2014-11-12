#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 5;
int equ,var;/// equ个方程，var个变量
int a[maxn][maxn];
int x[maxn];///解
bool free_x[maxn];///不确定变元
int free_num;
void debug()
{
    for(int i=0;i<equ;i++)
    {
        for(int j=0;j<var+1;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
/// -2表示浮点解 -1表示无解 0表示唯一解 大于0表示自由变元个数
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
                LCM=lcm(abs(a[i][col]),abs(a[k][col]));
                ta=LCM/abs(a[i][col]);
                tb=LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0)
                    tb=-tb;
                for(j=col;j<var+1;j++)
                    a[i][j]=a[i][j]*ta-a[k][j]*tb;
            }
        }
    }
    for(i=k;i<equ;i++)
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
    }
    for(i=var-1;i>=0;i--)
    {
        tmp=a[i][var];
        for(j=i+1;j<var;j++)
            if(a[i][j]!=0)
                tmp-=a[i][j]*x[j];
        if(tmp%a[i][i]!=0)
            return -2;
        x[i]=tmp/a[i][i];
    }
    return 0;
}
int main()
{
    equ=3;
    var=3;
    int cnt[4][4];
    int xx,yy,zz;
    int ans;
    scanf("%d%d%d",&xx,&yy,&zz);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&cnt[i][j]);
    for(ans=1;ans<101;ans++)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[j][i]=cnt[i][j];
        a[0][3]=ans*xx;
        a[1][3]=ans*yy;
        a[2][3]=ans*zz;
        free_num=gauss();
        if(free_num>=0)
        {
            if(free_num==0)
            {
                if(x[0]<0||x[1]<0||x[2]<0)
                    continue;
                printf("%d %d %d %d\n",x[0],x[1],x[2],ans);
            }
            else
            {
                if((!free_x[0]&&x[0]<0)||(!free_x[1]&&x[1]<0)||(!free_x[2]&&x[2]<0))
                    continue;
                for(int i=0;i<3;i++)
                {
                    if(free_x[i])
                        printf("0 ");
                    else
                        printf("%d ",x[i]);
                }
                printf("%d\n",ans);
            }
            break;
        }
    }
    if(ans==101)
        printf("NONE\n");
    return 0;
}
