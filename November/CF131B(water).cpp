// Opposites Attract
// http://codeforces.com/problemset/problem/131/B
// water

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
map<int,LL>mp;
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        while(n--){
            scanf("%d",&x);
            mp[x]++;
        }
        map<int,LL>::iterator it;
        LL ans=0;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->first==0){
                ans+=(it->second-1)*it->second/2;
            }
            else if(it->first>0){
                ans+=it->second*mp[-it->first];
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
