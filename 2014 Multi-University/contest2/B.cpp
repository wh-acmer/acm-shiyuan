#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
#define maxn 40000
bool vis[maxn];
LL a[4500];
string multi(string a,LL b){
    LL r=0;
    for(int i=0;i<a.size();i++){
        r+=(a[i]-'0')*b;
        a[i]=(r%10+48);
        r/=10;
    }
    while(r){
        a+=(r%10+'0');
        r/=10;
    }
    return a;
}
vector<LL>prime;
map<LL,LL>mp;
void Prime(){
    memset(vis,true,sizeof(vis));
    vis[0]=vis[1]=false; prime.clear();
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i){
                vis[j]=false;
            }
        }
    }
}
void get_factor(LL n,LL tag){
    for(int i=0;i<prime.size() && prime[i]<=n;i++){
        while(n%prime[i]==0){
            n/=prime[i];
            a[i]+=tag;
        }
    }
    if(n!=1) mp[n]+=tag;
}
int main(){
    LL n,d;
    Prime();
    while(scanf("%I64d%I64d",&n,&d)!=EOF){
        memset(a,0,sizeof(a)); mp.clear();
        get_factor(d,1);
        get_factor(d-1,1);
        get_factor(n+4,2);
        get_factor(3,-2);
        get_factor(2,-1);
        get_factor(n,-d);
        string ans="1",ansb="1";
        for(int i=0;i<prime.size();i++){
            for(int j=0;j<a[i];j++){
                ans=multi(ans,prime[i]);
            }
            for(int j=0;j>a[i];j--){
                ansb=multi(ansb,prime[i]);
            }
        }
        map<LL,LL>::iterator it=mp.begin();
        for(;it!=mp.end();it++){
            int num=it->second;
            for(int i=0;i<num;i++){
                ans=multi(ans,it->first);
            }
            for(int i=0;i>num;i--){
                ansb=multi(ansb,it->first);
            }
        }
        reverse(ans.begin(),ans.end());
        reverse(ansb.begin(),ansb.end());
        if(ansb=="1"){
            printf("%s\n",ans.c_str());
        }
        else{
            printf("%s/%s\n",ans.c_str(),ansb.c_str());
        }
    }
    return 0;
}
