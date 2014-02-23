#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
string s;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=s.size()-1;j>=0;j--) cout<<s[j];
            cout<<endl;
        }
    }
    return 0;
}
