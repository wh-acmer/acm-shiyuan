// E - IBM Chill Zone
// http://codeforces.com/gym/100500/attachments/download/2712/syrian-collegiate-programming-contest-2014-en.pdf
// sg

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define N 60
int dp[N];
int n,k,T;
set<int>s;
void solve(){
    dp[0]=0;
    for(int i=1;i<=n;i++){
        s.clear();
        for(int j=0;j+k<=i;j++){
            s.insert(dp[j]^dp[i-k-j]);
        }
        int ans=0;
        while(s.find(ans)!=s.end()) ans++;
        dp[i]=ans;
    }
}
int main(){
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        cin>>n>>k;
        solve();
        cout<<"Case "<<cas<<": ";
        if(dp[n]) cout<<"Winning"<<endl;
        else cout<<"Losing"<<endl;
    }
    return 0;
}
