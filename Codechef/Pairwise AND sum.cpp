#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 100010
int a[maxn][31];
long long p[31];
int main(){
    p[0]=1;
    for(int i=1;i<31;i++)   p[i]=p[i-1]*2;
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        int pos=0;
        memset(a[i],0,sizeof(a[i]));
        while(x){
            a[i][pos++]=x&1;
            x>>=1;
        }
    }
    long long ans=0;
    for(int i=0;i<31;i++){
        long long cnt=0;
        for(int j=0;j<n;j++) cnt+=a[j][i];
        if(cnt==0) continue;
        cnt=(cnt-1)*cnt/2;
        ans+=cnt*p[i];
    }
    printf("%lld\n",ans);
    return 0;
}
