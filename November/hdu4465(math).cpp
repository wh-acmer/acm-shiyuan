// Candy
// http://acm.hdu.edu.cn/showproblem.php?pid=4465
// math

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
int main(){
    int n,cas=0;
    double p;
    while(scanf("%d%lf",&n,&p)!=EOF){
        double ans=0;
        double tmp=0;
        for(int i=n+1;i<=2*n;i++){
            tmp+=log(i*1.0/(i-n));
        }
        for(int i=0;i<=n;i++){
            double cnt=0;
            cnt+=(n+1)*log(p)+(n-i)*log(1-p)+tmp;
            ans+=i*exp(cnt);
            cnt=0;
            cnt+=(n+1)*log(1-p)+(n-i)*log(p)+tmp;
            ans+=i*exp(cnt);
            tmp+=log((n-i)/(2.0*n-i));
        }
        printf("Case %d: %.10f\n",++cas,ans);
    }
    return 0;
}
