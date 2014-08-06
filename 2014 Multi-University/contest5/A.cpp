#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 500000 + 5;
const int INF = 1000000000;
typedef long long LL;
typedef pair<LL, int> P;

int a[maxn];
int tem[maxn];

LL solve(int l, int r){
    if(l>=r) return 0;
    LL ret = 0;
    int mid = (l+r)/2;
    ret += solve(l, mid);
    ret += solve(mid+1, r);

    int pl = l, pr = mid+1;
    for(int pl = l;pl <= mid;pl++){
        for(int j = pr;j <= r;j++){
            if(a[pl]<=a[j]){
                break;
            }
            else
                pr++;
        }
        ret += pr-mid-1;
    }
    sort(a+l,a+r+1);
    return ret;
}
int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
        for(int i = 0;i < n;i++)
            scanf("%d", &a[i]);
        LL ans = solve(0, n-1);
        printf("%I64d\n", max(ans-k, 0ll));
    }
    return 0;
}
