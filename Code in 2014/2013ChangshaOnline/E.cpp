#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#define eps 1e-12
string s[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int day[7]={8,8,8,8,8,4,4};
int main()
{
    string str;
    while(cin>>str)
    {
        double v,l;
        cin>>l>>v;
        double week=v*(5*8+2*4);
        int now=0;
        for(int i=0;i<7;i++)
            if(s[i]==str)
                now=i;
        int tmp=l/week;
        l-=tmp*week;
        if(l<eps)
        {
            cout<<s[(now+6)%7]<<endl;
            continue;
        }
        while(l-day[now%7]*v>eps)
        {
            l-=day[now%7]*v;
            now++;
            now%=7;
        }
        cout<<s[now%7]<<endl;
    }
    return 0;
}
