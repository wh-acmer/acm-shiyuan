/*
    ���⣺n������ͬ��ɫ�·�����m���裬ÿ��3���˵��·�ֻ����1��2��3������
    ����m���裬3���˵ı�ţ���һ��������������ÿ�����·�����ɫ
    ˼·������һ�����ڽ⣬��ô����ÿ���ˣ����ڵ��ǳ��裬���ֻʣ��һ����ɫ����һ���ǣ���Ȼ������㸳��һ����
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
