/*
    dp

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
string s;
LL ans,C[30][30],dp[15][30];
bool ok(){
    for(int i=1;i<s.size();i++)
        if(s[i-1]>=s[i]) return false;
    return true;
}
int main(){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<26;i++) dp[0][i]=1;
    for(int i=1;i<15;i++)
        for(int j=0;j+i<26;j++){
            dp[i][j]=0; // 表示长度为i,最小位为j的个数
            for(int k=j+1;k+i-1<26;k++)
                dp[i][j]+=dp[i-1][k];
        }
    while(cin>>s){
        if(!ok()){
            printf("0\n");
            continue;
        }
        LL ans=0; int l=s.size();
        for(int i=0;i<l-1;i++)
            for(int j=0;j+i<26;j++)
                ans+=dp[i][j];
        for(int i=0;i<l;i++){
            int j=0;
            if(i==0) j=0;
            else j=s[i-1]-'a'+1;
            for(;j+'a'<s[i];j++)
                ans+=dp[l-1-i][j];
        }
        printf("%lld\n",++ans);
    }
    return 0;
}
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
string s;
LL ans,C[30][30];
void init_C(){
    memset(C,0,sizeof(C));
    for(int i=0;i<30;i++) C[i][i]=1,C[i][0]=1;
    for(int i=2;i<30;i++)
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
}
bool ok(){
    for(int i=1;i<s.size();i++)
        if(s[i-1]>=s[i]) return false;
    return true;
}
int main(){
    init_C();
    while(cin>>s){
        if(!ok()){
            printf("0\n");
            continue;
        }
        LL ans=0; int l=s.size();
        for(int i=1;i<l;i++) ans+=C[26][i];
        for(int i=0;i<l;i++){
            int j;
            if(i==0) j=0;
            else j=s[i-1]-'a'+1;
            for(; j+'a'<s[i];j++){
                ans+=C[25-j][l-i-1];
            }
        }
        printf("%lld\n",++ans);
    }
    return 0;
}
