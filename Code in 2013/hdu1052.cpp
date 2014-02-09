/*
    water
*/
#include <cstring>
#include <cmath>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>tian,qi;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        int horse;
        tian.clear();
        qi.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&horse);
            tian.push_back(horse);
        }
        sort(tian.begin(),tian.end());
        for(int i=0;i<n;i++)
        {
            scanf("%d",&horse);
            qi.push_back(horse);
        }
        sort(qi.begin(),qi.end());
        int qil=0,qir=n-1,tianl=0,tianr=n-1;
        int win=0,lose=0;
        for(int i=0;i<n;i++)
        {
            if(tian[tianl]>qi[qil])
            {
                win++;
                tianl++;
                qil++;
            }
            else if(tian[tianl]<qi[qil])
            {
                lose++;
                tianl++;
                qir--;
            }
            else
            {
                if(tian[tianr]>qi[qir])
                {
                    win++;
                    tianr--;
                    qir--;
                }
                else
                {
                    if(tian[tianl]<qi[qir])
                    {
                        lose++;
                        qir--;
                        tianl++;
                    }
                }
            }
        }
        printf("%d\n",200*(win-lose));
    }
    return 0;
}
