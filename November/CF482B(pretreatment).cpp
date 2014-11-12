// Interesting Array
// http://codeforces.com/problemset/problem/482/B
// pretreatment

// 预处理下,s[i][j]表示第i(<30)位的前j项和，当某位为0时，应存在若干位不为0

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N 100010
int l[N],r[N];
int a[30][N],s[30][N],q[N];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(a,0,sizeof a);
        memset(s,0,sizeof s);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&l[i],&r[i],&q[i]);
            int tmp=1;
            for(int j=0;j<30;j++){
                if(tmp&q[i]){
                    a[j][l[i]]++;
                    a[j][r[i]+1]--;
                }
                tmp<<=1;
            }
        }
        for(int i=0;i<30;i++){
            int now=0;
            for(int j=1;j<=n;j++){
                now+=a[i][j];
                s[i][j]=s[i][j-1]+(now>0);
            }
        }
        bool ok=true;
        for(int i=0;ok&&i<m;i++){
            int tmp=1;
            for(int j=0;ok&&j<30;j++){
                if(q[i]&tmp) ;
                else{
                    if(s[j][r[i]]-s[j][l[i]-1]==r[i]-l[i]+1){
                        ok=false;
                    }
                }
                tmp<<=1;
            }
        }
        if(ok){
            printf("YES\n");
            int ans;
            for(int i=1;i<=n;i++){
                int tmp=1;
                ans=0;
                for(int j=0;j<30;j++){
                    if(s[j][i]^s[j][i-1]){
                        ans|=tmp;
                    }
                    tmp<<=1;
                }
                printf("%d ",ans);
            }
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
