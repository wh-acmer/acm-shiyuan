#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
map<string,int>m;
int main()
{
    m.clear();
    map<string,int>::iterator it,se;
    string s;
    string str;
    int grade;
    double sum=0;
    while(cin>>s)
    {
        if(s=="QUIT")
            break;
        if(s=="NEW")
        {
            cin>>str;
            cin>>grade;
            se=m.find(str);
            if(se==m.end())
                printf("A new record\n");
            else
            {
                sum-=m[str];
                printf("update succeed\n");
            }
            m[str]=grade;
            sum+=grade;
        }
        else if(s=="MAX")
        {
            vector<string>v;
            v.clear();
            int mx=m.begin()->second;
            for(it=m.begin();it!=m.end();it++)
                mx=max(mx,it->second);
            for(it=m.begin();it!=m.end();it++)
            {
                if(it->second==mx)
                {
                    v.push_back(it->first);
                }
            }
            printf("%d %d\n",mx,v.size());
            sort(v.begin(),v.end());
            vector<string>::iterator ii=v.begin();
            for(;ii!=v.end();ii++)
                cout<<*ii<<endl;
        }
        else if(s=="AVERAGE")
        {
            printf("%.2lf\n",sum/m.size());
        }
        else if(s=="DELETE")
        {
            cin>>str;
            se=m.find(str);
            if(se==m.end())
                printf("no such record\n");
            else
            {
                sum-=se->second;
                m.erase(se);
                printf("delete succeed\n");
            }
        }
    }
    return 0;
}
