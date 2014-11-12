#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    string s,question,answer;
    map<string,int>m;
    map<string,int>v;
    map<string,bool>ac;
    while(scanf("%d",&t)!=EOF)
    {
        m.clear();
        v.clear();
        ac.clear();
        int cnt;
        for(int i=1;i<=t;i++)
        {
            cin>>s>>question>>answer;
            cnt=(((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0')-(18*60+0);
            //printf(" ==  %d\n",cnt);
            if(answer=="AC"&&!ac[question])
            {
                ac[question]=1;
                m[question]=cnt;
            }
            if(answer!="AC"&&!ac[question])
                v[question]++;
        }
        map<string,int>::iterator it=m.begin();
        int ans=0;
        for(;it!=m.end();it++)
            ans+=it->second+v[it->first]*20;
        printf("%02d:%02d\n",ans/60,ans%60);
    }
    return 0;
}
