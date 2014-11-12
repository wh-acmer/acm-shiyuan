// Cows and Sequence
// http://codeforces.com/problemset/problem/283/A
// water

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
int p[200010];
int q[200010];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        LL sum=0,num=1;
        memset(p,0,sizeof p);
        memset(q,0,sizeof q);
        for(int i=0;i<n;i++){
            int op,a,x;
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d",&a,&x);
                sum+=a*x;
                q[a-1]+=x;
            }
            else if(op==2){
                scanf("%d",&x);
                sum+=x;
                p[num++]=x;
            }
            else{
                num--;
                sum-=p[num]+q[num];
                q[num-1]+=q[num];
                q[num]=0;
            }
            printf("%.12f\n",sum*1.0/num);
        }
    }
    return 0;
}
