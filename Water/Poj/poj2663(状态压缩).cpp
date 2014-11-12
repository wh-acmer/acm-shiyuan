#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
struct Matrix
{
    int m[9][9];
}E,D;
void init()
{
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
        {
            E.m[i][j]=(i==j);
            D.m[i][j]=0;
        }

    D.m[1][2]=1;
    D.m[1][5]=1;
    D.m[1][8]=1;

    D.m[2][1]=1;
    D.m[2][7]=1;

    D.m[3][6]=1;

    D.m[4][5]=1;

    D.m[5][1]=1;
    D.m[5][4]=1;

    D.m[6][3]=1;

    D.m[7][2]=1;

    D.m[8][1]=1;
}
Matrix Multi(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
        {
            ans.m[i][j]=0;
            for(int k=1;k<=8;k++)
                ans.m[i][j]+=A.m[i][k]*B.m[k][j];
        }
    return ans;
}
Matrix Pow(Matrix A,int k)
{
    Matrix ans=E;
    while(k)
    {
        if(k&1)
        {
            k--;
            ans=Multi(ans,A);
        }
        else
        {
            k/=2;
            A=Multi(A,A);
        }
    }
    return ans;
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
            break;
        Matrix cnt=Pow(D,n);
        /*
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
                printf("%d ",cnt.m[i][j]);
            printf("\n");
        }
        */
        Matrix tmp;
        tmp.m[1][1]=1;
        for(int i=2;i<=8;i++)
            tmp.m[i][1]=0;
        Matrix ans;
        for(int i=1;i<=8;i++)
            for(int j=1;j<=1;j++)
            {
                ans.m[i][j]=0;
                for(int k=1;k<=8;k++)
                    ans.m[i][j]+=cnt.m[i][k]*tmp.m[k][j];
            }
        printf("%d\n",ans.m[1][1]);
    }
    return 0;
}


/*

    状态压缩
        对于每一列的3块砖用二进制表示

    对于当前的状态，要全部填满，并处理下一列的状态

    例如当前状态是 001

       0     处理之后的结果可以是  1 1  或者  1 0
       0                           1 1        1 0
       1                           1 0        1 0

    例如当前状态是 010

       0     处理之后的结果可以是  1 1
       1                           1 0
       0                           1 1

    同理可以得到其他对应的值


  八种状态      1表示可达 0表示不可达

             000    001    010    011    100    101    110    111
    000       0      1      0      0      1      0      0      1
    001       1      0      0      0      0      0      1      0
    010       0      0      0      0      0      1      0      0
    011       0      0      0      0      1      0      0      0
    100       1      0      0      1      0      0      0      0
    101       0      0      1      0      0      0      0      0
    110       0      1      0      0      0      0      0      0
    111       1      0      0      0      0      0      0      0









http://poj.org/problem?id=2411

    http://poj.org/problem?id=3420

        http://poj.org/problem?id=2663

*/


/*
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int dp[31][8];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=30;i++)
    {
        dp[i][0]=dp[i-1][1]+dp[i-1][4]+dp[i-1][7];
        dp[i][1]=dp[i-1][0]+dp[i-1][6];
        dp[i][2]=dp[i-1][5];
        dp[i][3]=dp[i-1][4];
        dp[i][4]=dp[i-1][3]+dp[i-1][0];
        dp[i][5]=dp[i-1][2];
        dp[i][6]=dp[i-1][1];
        dp[i][7]=dp[i-1][0];
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
            break;
        printf("%d\n",dp[n][0]);
    }
    return 0;
}
*/
/*
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int dp[31];
int solution(int n)
{
    if(n&1)
        return 0;
    if(n==0)
        return 1;
    if(n==2)
        return 3;
    int ans=3*solution(n-2);
    for(int i=0;i<n-2;i+=2)
        ans+=2*solution(i);
    return ans;
}
void solve()
{
    for(int i=0;i<=30;i++)
        dp[i]=solution(i);
}
int main()
{
    int n;
    solve();
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
            break;
        printf("%d\n",dp[n]);
    }
    return 0;
}
*/
