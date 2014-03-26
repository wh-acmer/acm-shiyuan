#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int C[33][33],p[33];
void init(){
    for(int i=0;i<33;i++) C[i][i]=1,C[i][0]=1,C[i][1]=i;
    for(int i=2;i<33;i++){
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
}
int solve(int n){
    int index=0,ans=0;
    while(n){
        p[++index]=n%2;
        n/=2;
    }
    for(int i=index-1;i>=1;i--){
        for(int j=(i+1)/2;j<=i-1;j++)
            ans+=C[i-1][j];
    }
    int one=1,zero=0;
    for(int i=index-1;i>=1;i--){
        if(p[i]){
            for(int j=i-1;j+zero+1>=(index+1)/2;j--)
                ans+=C[i-1][j];
            one++;
        }
        else{
            zero++;
        }
    }
    return ans;
}
int main(){
    int a,b; init();
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b) swap(a,b);
        printf("%d\n",solve(b+1)-solve(a));
    }
    return 0;
}
