#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <string>
using namespace std;
#define maxn 101
int m[maxn][maxn];
bool v[maxn];
int a,b,c;
void Print(int n){
    //printf("=========\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",m[i][j]);
            if(j==n) printf("\n");
            else printf(" ");
        }
    }
    //printf("=========\n");
}
int main(){
    int n,k,cas=0;
    while(scanf("%d%d",&n,&k)!=EOF){
            int K=k;
        printf("Case #%d:\n",++cas);
        if(k&1){
            if(k==1){
                printf("%d\n",n-1);
                for(int i=1;i<=n;i++){
                    printf("%d\n",i);
                }
            }
            else{
                if(n&1){
                    printf("0\n");
                    for(int i=1;i<=n;i++){
                        for(int j=1;j<k-2;j++){
                            if(j&1) printf("%d ",i);
                            else printf("%d ",n+1-i);
                        }
                        a=i;
                        b=(i+n/2)%n;
                        if(b==0) b+=n;
                        c=(n+1)/2*3-a-b;
                        printf("%d %d %d\n",a,b,c);
                    }
                }
                else{
                    printf("1\n");
                    for(int i=1;i<=n;i++){
                        for(int j=1;j<k-2;j++){
                            if(j&1) printf("%d ",i);
                            else printf("%d ",n+1-i);
                        }
                        a=i;
                        b=(i+n/2)%n;
                        if(b==0) b+=n;
                        c=(n+1)*3/2;
                        if(i<=n/2) c++;
                        c-=a+b;
                        printf("%d %d %d\n",a,b,c);
                    }
                }
            }
        }
        else{
            printf("0\n");
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k;j++){
                    if(j&1) printf("%d",i);
                    else printf("%d",n+1-i);
                    if(j==k) printf("\n");
                    else printf(" ");
                }
            }
        }
        if(n&1) printf("No\n");
        else{
            printf("Yes\n");
            if(n>100) continue;
            memset(m,0,sizeof(m));
            for(int i=1;i<=n;i++){
                m[i][1]=m[1][i]=i;
                m[i][i]=1;
            }
            int x;
            for(int i=2;i<n;i++){
                for(int j=2;j<n;j++){
                    x=j+i-1;
                    if(x>n){
                        x-=n-1;
                    }
                    if(j==i) m[j][x]=n;
                    else m[j][x]=i;
                }
            }
            for(int i=2;i<n;i++){
                memset(v,true,sizeof(v));
                for(int j=1;j<n;j++){
                    v[m[j][i]]=false;
                }
                for(int j=1;j<=n;j++){
                    if(v[j]){
                        m[n][i]=j;
                        break;
                    }
                }
            }
            //Print(n);
            for(int i=1;i<=n;i++){
                int now=i;
                printf("%d ",now);
                for(int j=2;j<=n;j++){
                    printf("%d",m[now][j]);
                    now=m[now][j];
                    if(j==n) printf("\n");
                    else printf(" ");
                }
            }
        }
    }
    return 0;
}
