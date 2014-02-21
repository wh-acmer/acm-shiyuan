#include <cstring>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
using namespace std;
typedef __int64 LL;
int num[4];
vector<int>v[1010];
int main(){
    int n,m,x,y,sum;
    while(scanf("%d%d",&n,&m)!=EOF){
        sum=0; memset(num,0,sizeof(num));
        for(int i=0;i<1010;i++) v[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                scanf("%1d%1d",&x,&y);
                if(x==0 && y==0) num[0]++;
                if(x==1 && y==0) num[1]++;
                if(x==0 && y==1) num[2]++;
                if(x==1 && y==1) num[3]++;
            }
        int kao=0,cao=num[1]+num[2];
        while(num[3]){
            if(v[kao].size()<=m-1) v[kao].push_back(3),num[3]--;
            else kao++,v[kao].push_back(3),num[3]--;
        }
        int nima=0;
        if(v[kao].size()) num[1]=m-v[kao].size(),nima=num[1];
        else num[1]=0;
        num[2]=cao-num[1];
        while(num[1]){
            if(v[kao].size()<=m-1) v[kao].push_back(1),num[1]--;
            else kao++,v[kao].push_back(1),num[1]--;
        }
        int wuwu=kao;
        while(num[0]){
            if(v[kao].size()<=m-1) v[kao].push_back(0),num[0]--;
            else kao++,v[kao].push_back(0),num[0]--;
        }
        while(num[2]){
            if(v[kao].size()<=m-1) v[kao].push_back(2),num[2]--;
            else break;
        }
        wuwu=kao;
        while(num[2]){
            if(v[kao].size()<=m-1){
                if((wuwu&1) == (kao&1)) v[kao].push_back(2),num[2]--;
                else v[kao].push_back(1),num[2]--;
            }
            else{
                kao++;
                if((wuwu&1) == (kao&1)) v[kao].push_back(2),num[2]--;
                else v[kao].push_back(1),num[2]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0) printf("00"); if(v[i][j]==1) printf("10");
                if(v[i][j]==2) printf("01"); if(v[i][j]==3) printf("11");
                if(j==m-1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;

}
