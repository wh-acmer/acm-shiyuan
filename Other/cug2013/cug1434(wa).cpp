/*
    WA �Ĵ���

    ˼·������֪����ȷ��
    ����󣬰��մ�С�����˳�����г�  7 5 3 1 2 4 6 ...
    Ȼ����СԪ�أ��������ҷֱ�õ�����
     1 2 4 6 7 5 3  ��  1 3 5 7 6 4 2
    �����Сֵ�� 2
    ����ɨһ�飬����ȥ����ȥ���嵽ǰ�漴�ɱ�֤�ֵ�����С
    ���ǲ�֪��ΪʲôWa��  ��
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;
deque<int>q;
vector<int>ans,tmp,cnt,pnt,knt;
int main(){
    int n,x;
    while(scanf("%d",&n)!=EOF){
        q.clear();
        while(!q.empty()) q.pop_back();
        int mx=0;
        ans.clear();
        for(int i=0;i<n;i++) scanf("%d",&x),ans.push_back(x),mx=max(mx,x);
        int now=1;
        sort(ans.begin(),ans.end());
        int st=ans[0];
        for(int i=0;i<ans.size();i++){
            if(now){
                q.push_front(ans[i]);
            }
            else{
                q.push_back(ans[i]);
            }
            now=1-now;
        }
        int index=0;
        for(int i=0;i<q.size();i++){
            if(q[i]==st){
                index=i;
                break;
            }
        }

        ans.clear(); // ��СԪ������
        ans.push_back(q[index]);
        now=index+1;
        while(now%q.size()!=index) ans.push_back(q[now%q.size()]),now++;

        pnt.clear(); // ��СԪ������
        for(int i=q.size()-1;i>=0;i--){
            if(q[i]==st){
                index=i;
                break;
            }
        }
        pnt.push_back(q[index]);
        now=index-1;
        while((now+q.size())%q.size()!=index) pnt.push_back(q[(now+q.size())%q.size()]),now--;

        int mi=0;
        for(int i=0;i<ans.size();i++){
            mi=max(abs(ans[i]-ans[(i+1)%ans.size()]),mi);
        }
        int largest_index=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==mx) largest_index=i; // largest_indexǰ�����ݶ��������
        }
        cnt.clear(),tmp.clear();
        tmp.assign(ans.begin(),ans.begin()+largest_index+1);
        int right=ans[0];
        for(int i=ans.size()-1;i>largest_index;i--){
            if(abs(right-ans[i-1])<=mi){
                tmp.push_back(ans[i]);
            }
            else{
                right=ans[i];
                cnt.push_back(ans[i]);
            }
        }
        sort(tmp.begin(),tmp.end());
        for(int i=cnt.size()-1;i>=0;i--) tmp.push_back(cnt[i]);


        largest_index=0;
        for(int i=0;i<pnt.size();i++){
            if(pnt[i]==mx) largest_index=i; // largest_indexǰ�����ݶ��������
        }
        cnt.clear();
        knt.assign(pnt.begin(),pnt.begin()+largest_index+1);
        right=pnt[0];
        for(int i=pnt.size()-1;i>largest_index;i--){
            if(abs(right-pnt[i-1])<=mi){
                knt.push_back(pnt[i]);
            }
            else{
                right=pnt[i];
                cnt.push_back(pnt[i]);
            }
        }
        sort(knt.begin(),knt.end());
        for(int i=cnt.size()-1;i>=0;i--) knt.push_back(cnt[i]);

        bool ok=true;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]<knt[i]){
                ok=false;
                break;
            }
            else if(tmp[i]>knt[i]){
                ok=true;
                break;
            }
        }
        if(!ok){
            for(int i=0;i+1<tmp.size();i++) printf("%d ",tmp[i]);
                printf("%d\n",tmp[tmp.size()-1]);
        }
        else{
            for(int i=0;i+1<knt.size();i++) printf("%d ",knt[i]);
                printf("%d\n",knt[knt.size()-1]);
        }

    }
    return 0;
}
