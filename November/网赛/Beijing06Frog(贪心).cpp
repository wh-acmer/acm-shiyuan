#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
#define maxn 200010
int a[maxn];
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=0,a[n+1]=m;
        sort(a+1,a+n+2);
        int now=0,ans=0,step=l;
        for(int i=1;i<=n+1;i++){
            int dis=a[i]-now;
            if(dis+step<=l){
                now=a[i];
                step+=dis;
            }
            else if(dis<=l){
                now=a[i];
                step=dis;
                ans++;
            }
            else if(dis>l){
                int cnt=dis/(l+1);
                ans+=cnt*2;
                int re=dis%(l+1);
                if(step+re<=l){
                    step+=re;
                    now=a[i];
                }
                else{
                    step=re;
                    now=a[i];
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
