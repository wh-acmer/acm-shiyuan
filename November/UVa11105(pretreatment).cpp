// Semi-prime H-numbers
// http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=41872
// water

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
#define N 1000010
bool a[N];
int sum[N];
vector<int>v;
void init(){
    v.clear();
    for(int i=5;i<N;i+=4){
        a[i]=true;
    }
    for(int i=5;i<N;i+=4){
        if(a[i]){
            v.push_back(i);
            for(int j=2*i;j<N;j+=i){
                a[j]=false;
            }
        }
    }
    LL now;
    memset(sum,0,sizeof sum);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            now=v[i];
            now*=v[j];
            if(now>=N) break;
            sum[now]=1;
        }
    }
    for(int i=1;i<N;i++){
        sum[i]+=sum[i-1];
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        printf("%d %d\n",n,sum[n]);
    }
    return 0;
}
