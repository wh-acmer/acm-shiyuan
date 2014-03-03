/*
#include <stdio.h>
#include <string.h>
typedef long long LL;
char s[21];
int l,m;
LL b[20];
LL a[20];
LL ans;
inline int input()
{
    int ret=0;int IsN=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') IsN=1;c=getchar();}
    while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
    return IsN?-ret:ret;
}
inline void dfs(int index,int now,LL num){
    if(now==m-1 && index==l){
        if(num>ans){
            ans=num;
            for(int i=0;i<m;i++) b[i]=a[i];
            return ;
        }
    }
    if(now>=m || index>=l) return ;
    if(index==0){
        a[now]=s[index++]-'0';
        num*=a[now];
        dfs(index,now,num);
    }
    else{
        /// this number belong to the former
        LL pnt=a[now];
        if(a[now]!=0){
            LL pnum=num/a[now];
            a[now]=a[now]*10+s[index]-'0';
            dfs(index+1,now,pnum*a[now]);
        }
        ///  this number belong to the next part
        a[now]=pnt;
        now++;
        a[now]=s[index]-'0';
        dfs(index+1,now,num*a[now]);
    }
}
int main(){
    int T; T=input();
    while(T--){
        scanf("%s",&s); m=input();
        l=strlen(s); ans=-1;
        dfs(0,0,1);
        printf("%lld\n",ans);
        for(int i=0;i+1<m;i++) printf("%lld ",b[i]);
        printf("%lld\n",b[m-1]);
    }
    return 0;
}

*/

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
stack<LL>st;
char s[25];
P p[25][25];
LL dp[25][25];
LL num[25][25];
int l,m;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        while(!st.empty()) st.pop();
        scanf("%s%d",&s,&m); l=strlen(s);
        /*int num_zero=0;
        for(int i=0;i<l;i++) num_zero+=(s[i]-'0'==0);
        if(l-num_zero<m){
            printf("0\n");
            for(int i=0;i<l;i++,m--){
                printf("%c",s[i]);
                if(m) printf(" ");
            }
            printf("\n");
            continue;
        }*/
        for(int i=0;i<l;i++){
            num[i][i]=s[i]-'0';
            for(int j=i+1;j<l;j++)
                num[i][j]=num[i][j-1]*10+s[j]-'0';
        }
        memset(dp,0,sizeof(dp)); dp[0][0]=1;
        for(int i=0;i<l;i++){
            dp[i][1]=num[0][i];
            p[i][1]=P(0,i);
            for(int j=0;j<=m;j++){
                for(int k=0;k+1<=i;k++){
                    if(dp[k][j-1]*num[k+1][i]>=dp[i][j]){
                        dp[i][j]=dp[k][j-1]*num[k+1][i];
                        p[i][j]=P(k+1,i);
                    }
                }
            }
        }
        printf("%lld\n",dp[l-1][m]);
        int ans=dp[l-1][m];
        while(m){
            st.push(num[p[l-1][m].first][p[l-1][m].second]);
            l-=p[l-1][m].second-p[l-1][m].first+1; m--;
        }
        while(st.size()>1){
            printf("%lld ",st.top());
            st.pop();
        }
        printf("%lld \n",st.top());
    }
    return 0;

}
