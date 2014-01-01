#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int a[26];
int main(){
    int n,k;
    string s;
    while(cin>>n>>k){
        cin>>s;
        int ans=0;
        if(k==2){
            int x=0,y=0;
            for(int i=0;i<s.size();i++){
                if(i&1){
                    if(s[i]=='A') x++;
                    else  y++;
                }
                else{
                    if(s[i]=='B') x++;
                    else y++;
                }
            }
            if(x>y){
                cout<<y<<endl;
                for(int i=0;i<s.size();i++){
                    if(i&1) cout<<"A";
                    else cout<<"B";
                }
            }
            else {
                cout<<x<<endl;
                for(int i=0;i<s.size();i++){
                    if(i&1) cout<<"B";
                    else cout<<"A";
                }
            }
            cout<<endl;
            continue;
        }
        int tmp=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                tmp++;
                if(i==s.size()-1) ans+=tmp/2;
            }
            else    ans+=tmp/2,tmp=1;
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            if(i==0 || s[i]!=s[i-1])  ;
            else if(i+1>=n){
                for(int j=0;j<k;j++){
                    if(j+'A'!=s[i-1]){
                        s[i]='A'+j;
                        break;
                    }
                }
            }
            else {
                for(int j=0;j<k;j++){
                    if(j+'A'!=s[i-1] && j+'A'!=s[i+1]){
                        s[i]='A'+j;
                        break;
                    }
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
