/*
    Ñ­»·½Ú
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int a[210],c[210];
char s[210],str[210],cc;
int main(){
    int n,tmp,cnt,ans,m;
    while(scanf("%d",&n)!=EOF && n!=0){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            cnt=a[i];
            tmp=a[cnt];
            ans=1;
            while(tmp!=a[i]){
                cnt=tmp;
                tmp=a[cnt];
                ans++;
            }
            c[i]=ans;
        }
        memset(s,' ',sizeof(s));
        while(scanf("%d",&m)&&m){
            getchar();
            gets(s);
            int l=strlen(s);
            for(int i=l;i<=n;i++) s[i]=10;
            memset(str,' ',sizeof(str));
            for(int i=0;i<l;i++){
                tmp=m%c[i+1];
                cnt=i+1;
                while(tmp--) cnt=a[cnt];
                str[cnt-1]=s[i];
            }
            str[n]='\0';
            puts(str);
        }
        printf("\n");
    }
    return 0;
}
