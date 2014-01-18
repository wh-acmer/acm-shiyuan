/*
    题意：n个人分成3人一队的队伍，已知m条要求：队员i一定会跟队员j分在一个队中，输出满足的任意一种分组
    思路：优先考虑度为2的点，将与它相连接的点去掉组成3个人的队伍；剩下考虑两个度为1的点，加上一个度为0的；最后组合三个度为0的
*/
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
vector<int>v[50];
vector<int>ans;
vector<int>v0;
vector<int>v1;
bool vis[50];
int main(){
    int n,m,x,y;
    while(scanf("%d%d",&n,&m)!=EOF){
        ans.clear();
        v0.clear();
        v1.clear();
        for(int i=1;i<=n;i++){
            v[i].clear();
            vis[i]=true;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            v[y].push_back(x);
            v[x].push_back(y);
        }
        bool ok=true;
        for(int i=1;i<=n;i++){
            if(v[i].size()>2){
                ok=false;
            }
        }
        if(ok==false){
            printf("-1\n");
            continue;
        }
        while(1){
            bool over=false;
            for(int i=1;i<=n;i++){
                if(vis[i])
                    over=true;
            }
            if(over==false)
                break;
            for(int i=1;i<=n;i++){
                if(vis[i] && v[i].size()==2){
                    x=v[i][0],y=v[i][1];
                    for(int k=0;k<v[x].size();k++){
                        if(v[x][k]!=y && v[x][k]!=i)
                            ok=false;
                    }
                    for(int k=0;k<v[y].size();k++){
                        if(v[y][k]!=x && v[y][k]!=i)
                            ok=false;
                    }
                    vis[x]=false;
                    vis[y]=false;
                    vis[i]=false;
                    ans.push_back(i);
                    ans.push_back(x);
                    ans.push_back(y);
                }
            }
            for(int i=1;i<=n;i++){
                if(vis[i] && v[i].size()==1){
                    v1.push_back(i);
                    v1.push_back(v[i][0]);
                    vis[i]=false;
                    vis[v[i][0]]=false;
                }
                else if(vis[i] && v[i].size()==0){
                    v0.push_back(i);
                    vis[i]=false;
                }
            }
            if((v0.size()-v1.size()/2)%3)
                ok=false;
        }
        if(ok){
            for(int i=0;i<ans.size();i+=3)
                printf("%d %d %d\n",ans[i],ans[i+1],ans[i+2]);
            int j=0;
            for(int i=0;i<v1.size();i+=2)
                printf("%d %d %d\n",v1[i],v1[i+1],v0[j++]);
            for(;j<v0.size();j+=3)
                printf("%d %d %d\n",v0[j],v0[j+1],v0[j+2]);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
