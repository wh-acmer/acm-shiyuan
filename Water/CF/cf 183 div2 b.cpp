#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool is_leap(int n)
{
    if(n%4==0)
    {
        if(n%100==0)
        {
            if(n%400==0)
                return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}
int main()
{
    int ya,yb,ma,mb,da,db;
    scanf("%d:%d:%d",&ya,&ma,&da);
    scanf("%d:%d:%d",&yb,&mb,&db);
    int ans=0;
    if(ya>yb||(ya==yb&&ma>mb)||(ya==yb&&ma==mb&&da>db))
    {
        swap(ya,yb);
        swap(ma,mb);
        swap(da,db);
    }
    while(ya!=yb||ma!=mb||da!=db)
    {
        ans++;
        da++;
        if(is_leap(ya))
            month[2]=29;
        else
            month[2]=28;
        if(da>month[ma])
        {
            da%=month[ma];
            ma++;
        }
        if(ma>12)
        {
            ma%=12;
            ya++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
