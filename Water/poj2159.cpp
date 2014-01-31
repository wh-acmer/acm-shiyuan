#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[26],b[26],l;
char s[101];
int main(){
    while(scanf("%s",&s)!=EOF){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        l=strlen(s);
        for(int i=0;i<l;i++) a[s[i]-'A']++;
        scanf("%s",&s);
        l=strlen(s);
        for(int i=0;i<l;i++) b[s[i]-'A']++;
        sort(a,a+26);
        sort(b,b+26);
        bool ok=true;
        for(int i=0;i<26;i++) if(a[i]!=b[i]) ok=false;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
