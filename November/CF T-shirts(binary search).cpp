// Problem D. T-shirts
// http://codeforces.com/gym/100500/attachments/download/2712/syrian-collegiate-programming-contest-2014-en.pdf
// stl

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
#define N 100010
LL a[N];
int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        LL n,d,c;
        cin>>n>>d>>c;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        vector<int>v;
        v.assign(a,a+n);
        v.erase(unique(v.begin(),v.end()),v.end());
        LL ans=d*n,tmp;
        for(int i=0;i<v.size();i++){
            int index=upper_bound(a,a+n,v[i])-a;
            tmp=v[i]*c*index;
            tmp+=(n-index)*d;
            ans=min(ans,tmp);
        }
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
    return 0;
}
