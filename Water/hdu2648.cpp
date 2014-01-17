/*
    water
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
int main(){
    int n,m;
    map<string,int>mp;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        string s;
        int tmp;
        for(int i=0;i<n;i++){
            cin>>s;
            mp[s]=0;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>tmp>>s;
                mp[s]+=tmp;
            }
            map<string,int>::iterator it=mp.begin();
            int mx=mp["memory"];
            int ans=0;
            for(;it!=mp.end();it++){
                if(it->second>mx){
                    ans++;
                }
            }
            printf("%d\n",ans+1);
        }
    }
    return 0;
}
