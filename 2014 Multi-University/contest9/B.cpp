#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<cmath>
using namespace std;
const int maxn = 100000 + 5;
const int INF = 1000000000;
const double eps = 1e-6;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> P;
#define fi first
#define se second

LL far_mul[maxn], near_mul[maxn], a[maxn], b[maxn], c[maxn];

int main(){
    int n;
    while(scanf("%d", &n)){
        if(n == 0)
            break;
        memset(far_mul, -1, sizeof far_mul);
        memset(near_mul, -1, sizeof near_mul);
        for(int i = 1;i <= n;i++){
            scanf("%I64d", &a[i]);
        }
        for(int i = 1;i <= n;i++){
            if(near_mul[a[i]] != -1)
                b[i] = near_mul[a[i]];
            else
                b[i] = a[i];
            for(LL j = 1;j*j <= a[i];j++){
                if(a[i]%j==0){
                    near_mul[j] = a[i];
                    near_mul[a[i]/j] = a[i];
                }
            }
            near_mul[a[i]] = a[i];
        }
        for(int i = n;i >= 1;i--){
            if(far_mul[a[i]] != -1){
                c[i] = far_mul[a[i]];
            }
            else{
                c[i] = a[i];
            }
            for(LL j = 1;j*j <= a[i];j++){
                if(a[i]%j==0){
                    far_mul[a[i]/j] = a[i];
                    far_mul[j] = a[i];
                }
            }
            far_mul[a[i]] = a[i];

        }
        LL ans = 0;
        for(int i = 1;i <= n;i++){
            //cout << b[i] << ' ' << c[i] << endl;
            ans += c[i]*b[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
