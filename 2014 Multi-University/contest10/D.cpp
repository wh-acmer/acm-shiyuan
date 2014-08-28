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
const int maxn = 100 + 5;
const long long INF = 1e12;
const double eps = 1e-6;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> P;
#define fi first
#define se second

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        kase++;
        int n;
        LL sum = 0;
        scanf("%d", &n);
        LL Max = 0;
        while(n--){
            LL x;
            scanf("%I64d", &x);
            sum += x;
            Max = max(Max, x);
        }

        printf("Case #%d: %I64d\n", kase, max((sum+1)/2, Max));
    }
    return 0;
}
