// feixingjian
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<iostream>
#include<queue>
#include<cmath>
#include<string>
#include<set>
#include<map>
using namespace std;
const int maxn = 1000 + 5;
const int maxm = 1024;
const int mod = 1000000000 + 7;
const double eps = 1e-7;
const int INF = 1000000000;
typedef long long LL;
typedef pair<double, double> P;

int a[maxn];
LL dpl[maxn][maxm][2], dpr[maxn][maxm][2];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0;i < n;i++){
            scanf("%d", &a[i]);
        }
        memset(dpl, 0, sizeof dpl);
        memset(dpr, 0, sizeof dpr);
        for(int i = 0;i < n;i++)
            dpl[i][a[i]][1] = 1;
        //dpl[0][0][]
        for(int i = 1;i < n;i++){
            for(int j = 0;j < maxm;j++){
                dpl[i][j][1] = (dpl[i][j][1] + dpl[i-1][j^a[i]][1] + dpl[i-1][j^a[i]][0]) % mod;
                dpl[i][j][0] = (dpl[i][j][0] + dpl[i-1][j][1] + dpl[i-1][j][0]) % mod;
            }
        }
        for(int i = 0;i < n;i++)
            dpr[i][a[i]][1] = 1;
        //dpr[n-1][a[n-1]][1] = 1;
        for(int i = n-1;i > 0;i--){
            for(int j = 0;j < maxm;j++){
                dpr[i-1][j][0] = (dpr[i-1][j][0] + dpr[i][j][0] + dpr[i][j][1]) % mod;
                dpr[i-1][a[i-1]&j][1] = (dpr[i-1][a[i-1]&j][1] + dpr[i][j][0] + dpr[i][j][1]) % mod;
                //if(i==n-1 && j == 3) cout << (a[i-1]&j) << ' ' << dpr[i-1][a[i-1]&j][1] << endl;
            }
        }
        int ans = 0;
        //cout << dpl[0][1][1] << endl;
        //cout << dpl[1][1][1] << endl;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < maxm;j++){
                ans = (ans + dpl[i][j][1] * dpr[i][j][0]) % mod;
            }
        }
/*
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 10;j++){
                if(dpl[i][j][0] || dpl[i][j][1])
                    cout << i<<':'<<j << ' ' << dpl[i][j][0] << ' ' << dpl[i][j][1] << endl;
            }
        }
        cout << endl;
        for(int i = n-1;i >= 0;i--){
            for(int j = 0;j < 10;j++){
                if(dpr[i][j][0] || dpr[i][j][1])
                    cout << i<<':'<<j << ' ' << dpr[i][j][0] << ' ' << dpr[i][j][1] << endl;
            }
        }
    */
        printf("%d\n", ans);
    }
    return 0;
}
