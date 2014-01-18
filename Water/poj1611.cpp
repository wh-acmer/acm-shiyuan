/*
���⣺���0~n-1��n���ˣ����ֳ�m�飬ÿ���ڵ��˶����Դ�Ⱦ����֪0����Ⱦ���󱻸�Ⱦ��������
˼·����ʼ��ʱ���������������ܷ�ϲ�������󼯺���Ԫ�أ����RE�ˣ�����ջҲ����
�����������ǣ�ÿ������������ȸ���һ���˲�ͬ�ľͺϲ�����󿴸�0������ͬ������
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define maxn 30010
int pre[maxn];
int find(int x){
    if(x!=pre[x]){
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
void mix(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px>py) swap(px,py);
    pre[py]=px;
}
int main(){
    int n,m,x,y,k;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n+m==0)
            break;
        for(int i=0;i<n;i++)
            pre[i]=i;
        for(int i=1;i<=m;i++){
            scanf("%d",&k);
            scanf("%d",&x);
            for(int j=1;j<k;j++){
                scanf("%d",&y);
                if(find(x)!=find(y))
                    mix(x,y);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(find(0)==find(i))
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
