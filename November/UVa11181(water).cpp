// Probability|Given
// http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=18546
// 二进制枚举

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
vector<int>v;
double p[21];
double q[21];
int count(int n){
    int ans=0;
    while(n){
        if(n&1) ans++;
        n>>=1;
    }
    return ans;
}
int main(){
    int n,r,cas=0;
    while(scanf("%d%d",&n,&r)!=EOF){
        if(n==0 && r==0) break;
        printf("Case %d:\n",++cas);
        v.clear();
        for(int i=0;i<(1<<n);i++){
            if(count(i)==r){
                v.push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            scanf("%lf",&p[i]);
        }
        if(r==0){
            for(int i=0;i<n;i++){
                printf("%.10lf\n",0.0);
            }
            continue;
        }
        double total=0;
        for(int i=0;i<n;i++){
            double ans=0;
            for(int j=0;j<v.size();j++){
                int state=v[j];
                bool ok=false;
                double tmp=1;
                for(int k=0;k<n;k++){
                    if(state&1){
                        if(k==i) ok=true;
                        tmp*=p[k];
                    }
                    else{
                        tmp*=(1-p[k]);
                    }
                    state>>=1;
                }
                if(ok){
                    ans+=tmp;
                }
            }
            q[i]=ans;
            total+=ans;
        }
        for(int i=0;i<n;i++){
            q[i]/=total;
            printf("%.10lf\n",r*q[i]);
        }
    }
    return 0;
}
