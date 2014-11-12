#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    string a,b;
    while(t--)
    {
        cin>>a;
        cin>>b;
        int tag=1;
        int cnt=0,tmp=0;
        while(cnt!=a.length()&&tmp!=b.length())
        {
            if(a[cnt]==b[tmp])
            {
                cnt++;
                tmp++;
            }
            else if(a[cnt]=='@'&&b[tmp]=='%')
            {
                cnt++;
            }
            else if(a[cnt]=='%'&&b[tmp]=='@')
            {
                tmp++;
            }
            else if(a[cnt]!=b[tmp]&&(a[cnt]!='%'&&a[cnt]!='@'&&b[tmp]!='%'&&b[tmp]!='@'))
            {
                tag=-1;
                break;
            }
            else
            {
                tag=0;
                if(a[cnt]=='%'||a[cnt]=='@')
                    cnt++;
                else if(b[tmp]=='%'||b[tmp]=='@')
                    tmp++;
            }
        }
        if(tag==-1)
            printf("WrongAnswer\n");
        else if(tag==0)
            printf("PresentationError\n");
        else
            printf("Accepted\n");
    }
    return 0;
}
