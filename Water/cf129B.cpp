/*
    ���⣺����һ��n���㣬m���ߵ�ͼ��ÿ��ɾ����Ϊ1�ıߣ���Ҫɾ���ٴ�
    ˼·����һ����¼���������飬ѭ���ڣ��ҵ����м�¼ֵΪ1�ĵ㣬�Ѹ���Щ������ϵ�����е�Ķ�����һ
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
