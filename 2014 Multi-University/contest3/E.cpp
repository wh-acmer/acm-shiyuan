#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;
#define maxn 1000010
#define mx 100000
char s[maxn];
int main(){
    int n;
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        getchar();
        LL ans=1;
        int shit=0;
        int kuohao=0,meiyuan=0,kongge=0,shu=0;
        for(int ii=0;ii<n;ii++){
            gets(s);
            if(shit) continue;
            int l=strlen(s);
            int i=0;
            while(i<l){
                if(kuohao==0)
                if(s[i]=='$' && meiyuan==0){
                    meiyuan=1;
                    kongge=0;
                }
                else if(s[i]=='$' && meiyuan==1){
                    ans*=kongge+1;
                    if(ans>mx) shit=1;
                    meiyuan=0;
                }
                else if(meiyuan==1){
                    if(s[i]==' '){
                        kongge++;
                    }
                    else{
                        ans*=kongge+1;
                        if(ans>mx) shit=1;
                        kongge=0;
                    }
                }
                if(meiyuan==0)
                if(s[i]=='{' && kuohao==0){
                    kuohao=1;
                    shu=0;
                }
                else if(s[i]=='}' && kuohao==1){
                    kuohao=0;
                    ans*=shu+1;
                    if(ans>mx) shit=1;
                }
                else if(kuohao==1){
                    if(s[i]=='|'){
                        shu++;
                    }
                }
                i++;
            }
            if(ans>mx) shit=1;
        }
        if(shit) printf("doge\n");
        else printf("%I64d\n",ans);
    }
    return 0;
}
