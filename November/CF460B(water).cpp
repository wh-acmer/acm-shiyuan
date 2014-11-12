// Little Dima and Equation
// http://codeforces.com/problemset/problem/460/B
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int count(LL x){
    int ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
vector<int>v;
int main(){
    LL a,b,c;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF){
        v.clear();
        for(int i=1;i<=81;i++){
            LL x=b;
            for(int j=0;j<a;j++){
                x*=i;
            }
            x+=c;
            if(count(x)==i && x>0 && x<1000000000){
                v.push_back(x);
            }
        }
        printf("%d\n",v.size());
        if(v.size()==0) continue;
        for(int i=0;i<v.size();i++){
            printf("%d ",v[i]);
        }
        printf("\n");
    }
    return 0;
}
