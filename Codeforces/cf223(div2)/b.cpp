#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 100001
int a[maxn];
vector<int>v;
vector<int>w;
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        v.clear();
        w.clear();
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        v.push_back(a[n - 1]);
        int now = a[n - 1];
        for (int i = n - 2; i >= 0; i--){
            if (a[i] == now){
                if (v.size()==0)
                    v.push_back(a[i]);
                else if (v[v.size() - 1] != now)
                    v.push_back(a[i]);
            }
            else{
                w.push_back(a[i]);
                now = a[i];
            }
        }
        if (v.size() != 0 && w.size() != 0 && v[0] == w[0])
            printf("%d\n", v.size() + w.size()-1);
        else
            printf("%d\n", v.size() + w.size() );
        if (w.size() == 0)
        {
            printf("%d", v[0]);
            for (int i = 1; i < v.size(); i++)
                printf(" %d", v[i]);
            printf("\n");
        }
        else{
            printf("%d", w[w.size() - 1]);
            for (int i = w.size() - 2; i >= 0; i--)
                printf(" %d", w[i]);
            if (w[0] != v[0] && v.size()) printf(" %d", v[0]);
            for (int i = 1; i < v.size(); i++)
                printf(" %d", v[i]);
            printf("\n");
        }
    }
    return 0;
}
