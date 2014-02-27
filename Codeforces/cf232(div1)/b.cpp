#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define maxn 100000
#define pika 10000
vector<int>prime;
typedef long long LL;
LL gcd(LL a,LL b){
    if(b==0) return a; return gcd(b,a%b);
}
bool vis[maxn],cnt[2*pika+10];
int main(){
    memset(vis,true,sizeof(vis)); vis[0]=vis[1]=false;
    for(int i=2;i<maxn;i++){
        if(vis[i]){
            prime.push_back(i);
            for(int j=2*i;j<maxn;j+=i) vis[j]=false;
        }
    }
    int n,T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        LL mi,mx;
        if(n<maxn){
            for(int i=0;i<prime.size();i++){
                if(prime[i]<=n) mi=prime[i];
                if(prime[i]>n) {mx=prime[i];break;}
            }
        }
        else{
            int l=n-pika,r=n+pika,tmp;
            memset(cnt,true,sizeof(cnt));
            for(int i=0;i<prime.size();i++){
                tmp=l/prime[i];
                while(tmp*prime[i]<l||tmp<=1) tmp++;
                for(int j=tmp*prime[i];j<=r;j+=prime[i]){
                    if(j>=l && j<=r) cnt[j-l]=0;
                }
            }
            if(l==1) cnt[0]=0;
            for(int i=n;i>=0;i--){
                if(cnt[i-l]){
                    mi=i; break;
                }
            }
            for(int i=n+1;i<n+pika;i++){
                if(cnt[i-l]){
                    mx=i; break;
                }
            }
        }
        LL fenzi=mi*(mx-2)-2*(mx-1-n);
        LL fenmu=2*mi*mx;
        LL g=gcd(fenzi,fenmu);
        fenzi/=g,fenmu/=g;
        printf("%I64d/%I64d\n",fenzi,fenmu);
    }
    return 0;
}
