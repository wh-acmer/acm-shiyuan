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
const int maxn = 5000 + 5;
const int INF = 1e9;
const double eps = 1e-6;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> P;
#define fi first
#define se second

int cost[maxn];
int dp[maxn][maxn];
int a[maxn];
LL v[maxn];

void cal(int n){
    for(int i = 3;i <= n;i++){
        for(int j = 1;j < i;j++){
            a[i] = min(a[i], a[2]+a[j]+a[i-j]);
        }
    }
    /*
    for(int i = 1;i <= n;i++)
        cout << a[i] << ' ';
    cout << endl;
    */
}

int solve(int l, int r){
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l >= r)
        return dp[l][r] = 0;
    LL suml = v[l], sumr = v[r];
    int Min = a[r-l+1];
    int posl = l, posr = r;
    while(posl < posr){
        if(suml == sumr){
            Min = min(Min, a[posl-l+1]+a[r-posr+1]+solve(posl+1, posr-1));
            posl++;
            posr--;
            suml += v[posl];
            sumr += v[posr];
        }
        else if(suml > sumr){
            posr--;
            sumr += v[posr];
        }
        else if(suml < sumr){
            posl++;
            suml += v[posl];
        }
    }
    return dp[l][r] = Min;
}


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(scanf("%d", &n)){
        if(n == 0)
            break;
        for(int i = 0;i < n;i++)
            scanf("%I64d", &v[i]);
        for(int i = 1;i <= n;i++)
            scanf("%d", &a[i]);
        //cout << 'a';
        memset(cost, -1, sizeof cost);
        memset(dp, -1, sizeof dp);
        //cal(n);
        printf("%d\n", solve(0, n-1));
    }
    return 0;
}
