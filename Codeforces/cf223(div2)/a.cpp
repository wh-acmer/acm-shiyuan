#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
deque<int>q;
int main(){
    int n, x;
    while (scanf("%d", &n) != EOF){
        while (!q.empty()) q.pop_back();
        for (int i = 0; i < n; i++){
            scanf("%d", &x);
            q.push_back(x);
        }
        int ans = 0, other = 0;
        int now = 1;
        while (!q.empty()){
            if (now&1){
                if (q.front()>q.back()){
                    ans += q.front();
                    q.pop_front();
                }
                else{
                    ans += q.back();
                    q.pop_back();
                }
                now++;
            }
            else{
                if (q.front()>q.back()){
                    other += q.front();
                    q.pop_front();
                }
                else{
                    other += q.back();
                    q.pop_back();
                }
                now++;
            }
        }
        printf("%d %d\n", ans, other);
    }
    return 0;
}
