#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int h1,h2,s1,s2;
    while(scanf("%d:%d",&h1,&s1)!=EOF){
        scanf("%d:%d",&h2,&s2);
        int ans=0;
        while(h1!=h2 || s1!=s2){
            ans++;
            s2++;
            if(s2==60) s2=0,h2++;
            if(h2==24) h2=0;
        }
        printf("%02d:%02d\n",ans/60,ans%60);
    }
    return 0;
}
