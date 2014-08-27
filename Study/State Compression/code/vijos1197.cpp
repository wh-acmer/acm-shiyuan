#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a[5][5],b[5],s[5],cnt[1<<5],c[5];
void init(){
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<(1<<5);i++){
        int tmp=i;
        while(tmp){
            if(tmp&1) cnt[i]++;
            tmp>>=1;
        }
    }
}
int main(){
    int T;
    init();
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<5;i++){
            b[i]=0;
            for(int j=4;j>=0;j--){
                scanf("%1d",&a[i][j]);
                if(a[i][j]){
                    b[i]|=(1<<j);
                }
            }
        }
        int ans=25;
        for(int i=0;i<(1<<5);i++){
            int total=0;
            for(int j=0;j<5;j++){
                c[j]=b[j];
            }
            s[0]=i;
            c[0]^=((s[0]<<1)&((1<<5)-1))^(s[0]>>1)^s[0];
            c[1]^=s[0];
            total+=cnt[i];
            if(total>6) continue;
            for(int j=1;j<5;j++){
                s[j]=(1<<5)-1-c[j-1];
                total+=cnt[s[j]];
                if(total>6) break;
                c[j]^=((s[j]<<1)&((1<<5)-1))^(s[j]>>1)^s[j];
                c[j+1]^=s[j];
            }
            if(total>6) continue;
            if(c[4]==(1<<5)-1){
                int tmp=0;
                for(int j=0;j<5;j++){
                    tmp+=cnt[s[j]];
                }
                if(tmp<ans) ans=tmp;
            }
        }
        if(ans>6) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
