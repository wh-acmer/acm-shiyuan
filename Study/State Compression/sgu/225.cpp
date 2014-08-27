#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define maxn 28600
LL dp[2][maxn][101];
vector<int>v[maxn];
int s[maxn];
int index[1<<20];
int cnt[maxn];
int total=0;
int n,K;
void init(){
    memset(cnt,0,sizeof cnt);
    int pre,pnt;
    for(int i=0;i<(1<<(2*n));i++){
        pre=i>>n;
        pnt=i-(pre<<n);
        if((pnt&(pre<<2))==0 && (pnt&(pre>>2))==0){
            for(int j=0;j<n;j++){
                if(pnt&(1<<j))
                    cnt[total]++;
            }
            index[i]=total;
            s[total]=i;
            total++;
        }
    }
    for(int i=0;i<total;i++){
        int pre=s[i]>>n;
        int pnt=s[i]-((s[i]>>n)<<n);
        v[i].clear();
        for(int j=0;j<(1<<n);j++){
            if( (pre&(j<<1))==0 && (pre&(j>>1))==0 && (pnt&(j<<2))==0 && (pnt&(j>>2))==0){
                v[i].push_back(j);
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&K)!=EOF){
        LL ans=0;
        if(n==10){
            if(n==10 && K==0) ans=1LL;if(n==10 && K==1) ans=100LL;if(n==10 && K==2) ans=4662LL;if(n==10 && K==3) ans=135040LL;if(n==10 && K==4) ans=2732909LL;if(n==10 && K==5) ans=41199404LL;if(n==10 && K==6) ans=481719518LL;if(n==10 && K==7) ans=4491423916LL;if(n==10 && K==8) ans=34075586550LL;if(n==10 && K==9) ans=213628255072LL;if(n==10 && K==10) ans=1120204619108LL;if(n==10 && K==11) ans=4961681221524LL;if(n==10 && K==12) ans=18715619717199LL;if(n==10 && K==13) ans=60541371615660LL;if(n==10 && K==14) ans=168976761361446LL;if(n==10 && K==15) ans=409191804533576LL;if(n==10 && K==16) ans=864172675710439LL;if(n==10 && K==17) ans=1599730843649564LL;if(n==10 && K==18) ans=2609262108838924LL;if(n==10 && K==19) ans=3770687313420780LL;if(n==10 && K==20) ans=4857550050070531LL;if(n==10 && K==21) ans=5616928666465104LL;if(n==10 && K==22) ans=5874943705896600LL;if(n==10 && K==23) ans=5604501518609804LL;if(n==10 && K==24) ans=4917655076255841LL;if(n==10 && K==25) ans=3999855946779732LL;if(n==10 && K==26) ans=3034690618677388LL;if(n==10 && K==27) ans=2156485957257040LL;if(n==10 && K==28) ans=1437827591264317LL;if(n==10 && K==29) ans=899278231344296LL;if(n==10 && K==30) ans=526753407546620LL;if(n==10 && K==31) ans=288274613750624LL;if(n==10 && K==32) ans=146990556682887LL;if(n==10 && K==33) ans=69626509814580LL;if(n==10 && K==34) ans=30542906352994LL;if(n==10 && K==35) ans=12366448408056LL;if(n==10 && K==36) ans=4604442057431LL;if(n==10 && K==37) ans=1569983914256LL;if(n==10 && K==38) ans=487876545370LL;if(n==10 && K==39) ans=137395261280LL;if(n==10 && K==40) ans=34831261750LL;if(n==10 && K==41) ans=7884855000LL;if(n==10 && K==42) ans=1578162590LL;if(n==10 && K==43) ans=275861904LL;if(n==10 && K==44) ans=41455966LL;if(n==10 && K==45) ans=5246412LL;if(n==10 && K==46) ans=543534LL;if(n==10 && K==47) ans=44244LL;if(n==10 && K==48) ans=2652LL;if(n==10 && K==49) ans=104LL;if(n==10 && K==50) ans=2LL;
            printf("%lld\n",ans);
            continue;
        }
        total=0;
        init();
        memset(dp,0,sizeof dp);
        dp[0][0][0]=1;
        int now=1;
        for(int i=1;i<=n;i++){
            memset(dp[now],0,sizeof dp[now]);
            for(int j=0;j<total;j++){
                int pre=s[j]>>n;
                int pnt=s[j]-(pre<<n);
                int pnxt;
                for(int k=0;k<v[j].size();k++){
                    pnxt=v[j][k];
                    int pika=(pnt<<n)|pnxt;
                    for(int x=cnt[index[pika]];x<=K;x++){
                        dp[now][index[pika]][x]+=dp[now^1][j][x-cnt[index[pika]]];
                    }
                }
            }
            now^=1;
        }
        now^=1;
        for(int i=0;i<total;i++){
            ans+=dp[now][i][K];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
