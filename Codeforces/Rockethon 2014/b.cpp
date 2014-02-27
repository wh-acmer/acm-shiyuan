#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v[26];
string s;
int main(){
    while(cin>>s){
        for(int i=0;i<26;i++) v[i].clear();
        int ans=0;
        for(int i=0;i<s.size();i++){
            v[s[i]-'A'].push_back(i);
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<v[i].size();j++){
                int now=1,tmp=v[i][j];
                for(int k=j+1;k<v[i].size();k++){
                    if((v[i][k]-tmp)%2==1) now++,tmp=v[i][k];
                }
                ans=max(ans,now);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
