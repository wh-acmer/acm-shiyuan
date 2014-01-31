#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
#define maxn 100010
long long a[maxn];
map<long long,int>mp;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
        if(n==1) {
            printf("-1\n");
            continue;
        }
        sort(a,a+n);
        for(int i=1;i<n;i++){
            mp[a[i]-a[i-1]]++;
        }
        if(mp.size()==1){
            if(mp.begin()->first==0){
                printf("1\n");
                printf("%d\n",a[0]);
                continue;
            }
            else if(n==2 && (a[0]+a[1])%2==0){
                printf("3\n");
                map<long long,int>::iterator it=mp.begin();
                long long x1=it->first;
                long long x2=a[n-1]+x1;
                x1=a[0]-x1;
                printf("%I64d %I64d %I64d\n",x1,(a[0]+a[1])/2,x2);
                continue;
            }
            printf("2\n");
            map<long long,int>::iterator it=mp.begin();
            long long x1=it->first;
            long long x2=a[n-1]+x1;
            x1=a[0]-x1;
            printf("%I64d %I64d\n",x1,x2);
        }
        else if(mp.size()==2){
            map<long long,int>::iterator it=mp.begin(),ii=mp.begin();
            ii++;
            if(ii->second==1 && ii->first == 2*it->first){
                printf("1\n");
                for(int i=0;i<n;i++){
                    if(a[i]+ii->first==a[i+1]){
                        printf("%I64d\n",a[i]+it->first);
                    }
                }
            }
            else if(it->second==1 && it->first  == 2*ii->first){
                printf("1\n");
                for(int i=0;i<n;i++){
                    if(a[i]+it->first==a[i+1]){
                        printf("%I64d\n",a[i]+ii->first);
                    }
                }
            }
            else{
                printf("0\n");
            }
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
