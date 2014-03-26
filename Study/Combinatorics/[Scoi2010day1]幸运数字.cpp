#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
LL a,b;
LL luck[4100],MAXN=10000000001;
bool Luck[4100];
int num,s_num;
LL ans;
void dfs(LL now){
    if(now>MAXN) return ;
    luck[num++]=now;
    dfs(now*10+6);
    dfs(now*10+8);
}
void init(){
    num=0,s_num=0;
    dfs(0);
    sort(luck,luck+num);
    memset(Luck,0,sizeof(Luck));
    for(int i=1;i<num;i++){
        if(Luck[i]==0){
            for(int j=i+1;j<num;j++){
                if(luck[j]%luck[i]==0)
                    Luck[j]=1;
            }
        }
    }
    s_num=1;
    for(int i=1;i<num;i++){
        if(Luck[i]==0){
            luck[s_num++]=luck[i];
        }
    }
}
LL M;
LL gcd(LL a,LL b){
    if(b==0) return a; return gcd(b,a%b);
}
void s_dfs(int st,int tag,LL _num){
    for(int i=st;i>=1;i--){
        LL g=gcd(luck[i],_num);
        if(_num/g<=M/luck[i]){
            if(tag&1) ans-=M/(_num/g*luck[i]);
            else ans+=M/(_num/g*luck[i]);
            s_dfs(i-1,tag+1,_num/g*luck[i]);
        }
    }
}
LL get_num(LL x){
    ans=0;
    M=x;
    s_dfs(s_num,0,1);
    return ans;
}
int main(){
    init();
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        printf("%I64d\n",get_num(b)-get_num(a-1));
    }
    return 0;
}
