/*
    题意：给你一个n个点，m条边的图，每次删掉度为1的边，问要删多少次
    思路：开一个记录度数的数组，循环内，找到所有记录值为1的点，把跟这些点有联系的所有点的度数减一
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
vector<int>v[110];
vector<int>vv;
int du[110];
int n,m,x,y;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            v[i].clear();
            du[i]=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
            du[x]++;
            du[y]++;
        }
        int ans=0;
        while(1){
            bool ok=true;
            vv.clear();
            for(int i=1;i<=n;i++){
                if(du[i]==1){
                    du[i]=0;
                    ok=false;
                    vv.push_back(i);
                }
            }
            if(ok)
                break;
            ans++;
            for(int i=0;i<vv.size();i++){
                //cout<<vv[i]<<"......"<<endl;
                for(int j=0;j<v[vv[i]].size();j++){
                    du[v[vv[i]][j]]--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
