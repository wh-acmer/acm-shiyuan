#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define N 10010
typedef long long LL;
LL dp[N][8];
int a[N],n,b[4];
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof dp);
        if(n<=3){
            int ans=0;
            for(int i=0;i<(1<<n);i++){
                int tmp=i;
                for(int j=1;j<=n;j++){
                    b[j]=tmp&1;
                    tmp>>=1;
                }
                int ok=1;
                for(int i=1;i<=n;i++){
                    int now=b[i];
                    if(i-1>0) now+=b[i-1];
                    if(i+1<=n) now+=b[i+1];
                    if(now!=a[i]) ok=0;
                }
                if(ok){
                    ans++;
                }
            }
            printf("%d\n",ans);
            continue;
        }
        for(int i=0;i<(1<<3);i++){
            int tmp=i;
            for(int j=3;j>=1;j--){
                b[j]=tmp&1;
                tmp>>=1;
            }
            int ok=1;
            for(int j=1;j<=3;j++){
                int now=b[j];
                if(j-1>=1) now+=b[j-1];
                if(j+1<=3) now+=b[j+1];
                if(j<3 && now!=a[j])  ok=0;
                if(j==3 && now>a[j]) ok=0;
            }
            dp[3][i]=ok;
        }
        for(int i=4;i<=n;i++){
            for(int j=0;j<8;j++){
                int pnt=(j&1);
                int pre=(j&2)>>1;
                int prepre=(j&4)>>2;

                int now=pnt;
                now+=pre;
                if(now>a[i]) continue;  // check a[i]

                now+=prepre;
                if(now!=a[i-1]) continue;  // check a[i-1]

                for(int k=0;k<8;k++){
                    int kpnt=(k&1);
                    int kpre=(k&2)>>1;
                    int kprepre=(k&4)>>2;
                    if(kpre!=prepre) continue;
                    if(kpnt!=pre) continue;

                    int pnow=kpnt+pnt;
                    pnow+=kpre;
                    if(pnow==a[i-1])
                        dp[i][j]+=dp[i-1][k];
                }
            }
        }
        LL ans=0;
        for(int i=0;i<8;i++){
            int pnt=(i&1);
            int pre=(i&2)>>1;
            int prepre=(i&4)>>2;

            int now=pnt;
            if(i-1>=1) now+=pre;
            if(now!=a[n]) continue;

            if(i-2>=1) now+=prepre;
            if(i-1>=1 && now!=a[n-1]) continue;

            ans+=dp[n][i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
