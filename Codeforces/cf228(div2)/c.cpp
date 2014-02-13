#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int>v,vt;
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        v.clear();
        int ans=0;
        while(n--) scanf("%d",&x),v.push_back(x);
        sort(v.begin(),v.end());
        while(v.size()>0){
            int now=0;
            vt.clear();
            for(int i=0;i<v.size();i++){
                if(v[i]>=now) now++;
                else vt.push_back(v[i]);
            }
            v.assign(vt.begin(),vt.end());
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
