/*
    题意：n个穿不同颜色衣服人跳m场舞，每场3个人的衣服只会是1，2，3的排列
    给出m场舞，3个人的编号，求一种满足的条件输出每个人衣服的颜色
    思路：由于一定存在解，那么对于每个人，她在的那场舞，如果只剩下一种颜色，就一定是，不然，就随便赋予一个。
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 100010
int a[maxn][3];
int v[4];
int ans[maxn];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    }
    memset(ans,0,sizeof(ans));
    for(int i=0;i<m;i++){
        memset(v,0,sizeof(v));
        for(int j=0;j<3;j++){
            v[ans[a[i][j]]]=1;
        }
        for(int j=1;j<=3;j++){
            if(v[j]==0){
                for(int k=0;k<3;k++){
                    if(ans[a[i][k]]==0){
                        ans[a[i][k]]=j;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n-1;i++)
        cout<<ans[i]<<" ";
    cout<<ans[n]<<endl;
    return 0 ;
}
