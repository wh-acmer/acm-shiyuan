/*
    枚举起始点的情况
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
#define maxn 100010
string s;
int a[maxn];
int ans[11][maxn];
int main(){
    int n,k,w,x,y;
    while(scanf("%d%d%d",&n,&k,&w)!=EOF){
        cin>>s;
        for(int i=0;i<s.size();i++)
            if(s[i]=='1') a[i+1]=1;
            else a[i+1]=0;
        memset(ans,0,sizeof(ans));
        for(int st=0;st<11;st++){
            for(int j=st+1;j<=n;j++){
                ans[st][j]=ans[st][j-1];
                if((j-st)%k==0 && a[j]==0) ans[st][j]++;
                if((j-st)%k!=0 && a[j]==1) ans[st][j]++;
            }
        }
        while(w--){
            scanf("%d%d",&x,&y);
            int st=(x-1)%k;
            printf("%d\n",ans[st][y]-ans[st][x-1]);
        }
    }
    return 0;
}
