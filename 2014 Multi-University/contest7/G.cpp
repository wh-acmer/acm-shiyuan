// by feixingjian
#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<cmath>
using namespace std;
const int maxn = 200 + 5;
const int INF = 1000000000;
const double eps = 1e-6;
typedef long long LL;
typedef pair<LL, LL> P;
#define fi first
#define se second

map<LL, bool> existx, existy;
map<P, LL> pos;
map<LL, LL> hashx, hashy;

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        kase++;
        LL n, m, k;
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        existx.clear();
        existy.clear();
        pos.clear();
        hashx.clear();
        hashy.clear();
        while(k--){
            LL x, y, c;
            scanf("%I64d%I64d%I64d", &x, &y, &c);
            pos[P(x, y)] = c;
            existx[x] = true;
            existy[y] = true;
            hashx[x] = x;
            hashy[y] = y;
        }
        int q;
        scanf("%d", &q);
        printf("Case #%d:\n", kase);
        while(q--){
            int kind;
            LL a, b;
            scanf("%d%I64d%I64d", &kind, &a, &b);
            if(kind == 1){
                if(existx.count(a)>0 && existx.count(b)>0){
                    int A = hashx[a];
                    int B = hashx[b];
                    hashx[b] = A;
                    hashx[a] = B;
                }
            }
            else if(kind == 2){
                if(existy.count(a)>0 && existy.count(b)>0){
                    int A = hashy[a];
                    int B = hashy[b];
                    hashy[b] = A;
                    hashy[a] = B;
                }
            }
            else{
                int X = hashx[a];
                int Y = hashy[b];
                //cout << X << ':' << Y << endl;
                if(existx.count(a)>0 && existy.count(b)>0 && pos.count(P(X, Y)) > 0){
                    printf("%I64d\n", pos[P(X, Y)]);
                }
                else
                    printf("0\n");
            }
        }
    }
    return 0;
}
