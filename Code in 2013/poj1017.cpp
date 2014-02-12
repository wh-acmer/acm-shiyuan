/*
    greedy
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[7];
int main()
{
    //freopen("2.cpp","r",stdin);
    while(1)
    {
        bool ok=false;
        for(int i=1;i<=6;i++)
        {
            scanf("%I64d",&a[i]);
            if(a[i])
                ok=true;
        }
        if(!ok)
            break;
        long long ans=0;
        ans=a[6]+a[5]+a[4];
        if(a[5])
        {
            if(a[1])
            {
                a[1]-=11*a[5];
                if(a[1]<0)
                    a[1]=0;
            }
        }
        long long tmp;
        if(a[4])
        {
            tmp=a[4]*5;
            if(a[2]>=tmp)
                a[2]-=tmp;
            else
            {
                tmp=(tmp-a[2])*4;
                a[2]=0;
                a[1]-=tmp;
                if(a[1]<0)
                    a[1]=0;
            }
        }
        if(a[3])
        {
            ans+=(a[3]+3)/4;
            a[3]%=4;
            if(a[3]==0)
                ;
            else if(a[3]==1)
            {
                if(a[2]>=5)
                {
                    a[2]-=5;
                    a[1]-=27-5*2*2;
                    if(a[1]<0)
                        a[1]=0;
                }
                else
                {
                    a[1]-=27-a[2]*2*2;
                    a[2]=0;
                    if(a[1]<0)
                        a[1]=0;
                }
            }
            else if(a[3]==2)
            {
                if(a[2]>=3)
                {
                    a[2]-=3;
                    a[1]-=18-3*2*2;
                    if(a[1]<0)
                        a[1]=0;
                }
                else
                {
                    a[1]-=18-a[2]*2*2;
                    a[2]=0;
                    if(a[1]<0)
                        a[1]=0;
                }
            }
            else if(a[3]==3)
            {
                if(a[2])
                {
                    a[2]--;
                    a[1]-=5;
                    if(a[1]<0)
                        a[1]=0;
                }
                else
                {
                    a[1]-=9;
                    if(a[1]<0)
                        a[1]=0;
                }
            }
        }
        if(a[2])
        {
            ans+=(a[2]+8)/9;
            a[2]%=9;
            if(a[2]==0)
                ;
            else
            {
                a[1]-=36-a[2]*4;
                if(a[1]<0)
                    a[1]=0;
            }
        }
        ans+=(a[1]+35)/36;
        printf("%I64d\n",ans);
    }
    return 0;
}
