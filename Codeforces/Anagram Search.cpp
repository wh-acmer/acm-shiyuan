#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 100010
int a[maxn][26];
int b[26];
int main(){
    string s,str;
    while(cin>>s>>str){
        int l=str.size();
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++){
            for(int j=0;j<26;j++){
                if(j+'a'==s[i])  a[i][j]=a[i-1][j]+1;
                else    a[i][j]=(i-1>=0)?a[i-1][j]:0;
            }
        }
        memset(b,0,sizeof(b));
        for(int i=0;i<str.size();i++) b[str[i]-'a']++;
        int ans=0;
        for(int i=s.size()-1;i>=l-1;i--){
            for(int j=0;j<26;j++) a[i][j]=(i-l>=0)?(a[i][j]-a[i-l][j]):a[i][j];
            bool ok=true;
            for(int j=0;j<26;j++) if(a[i][j]>b[j]) ok=false;
            if(ok) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
