/*
    water
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
string a,b;
int main(){
    int T,n,cas=0;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>a>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]) ans+=a[i]-b[i];
            else ans+=b[i]-a[i];
        }
        cout<<"Case "<<++cas<<": "<<ans<<endl;
    }
    return 0;
}
