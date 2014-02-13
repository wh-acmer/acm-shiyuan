/*
    water
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
#define maxn 100010
long long a[maxn],b[maxn];
int main(){
    long long ans,x,y;
    int n;
    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        for(int i=0;i<n;i++){
            if(2*a[i]<b[i]){
                ans--;
            }
            else{
                x=b[i]/2;
                y=b[i]-x;
                if(x&&y)    ans+=x*y;
                else ans+=-1;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
