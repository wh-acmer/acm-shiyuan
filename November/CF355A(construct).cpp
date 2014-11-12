// Vasya and Digital Root
// http://codeforces.com/problemset/problem/355/A
// water

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int count(int n){
    int ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    if(ans<10) return ans;
    return count(ans);
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==1) printf("%d\n",k);
        else if(k==0 && n>1){
            printf("No solution\n");
        }
        else{
            string s="";
            for(int i=1;i<n;i++) s+="9";
            int ans=(n-1)*9;
            ans=count(ans);
            if(ans<k){
                ans=k-ans;
            }
            else{
                ans=k+9-ans;
            }
            s+=(ans+'0');
            printf("%s\n",s.c_str());
        }
    }
    return 0;
}
