#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
string s[21];
int num[26];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    scanf("%d",&t);
    int r,c,x,y;
    for(int cases=1;cases<=t;cases++)
    {
        scanf("%d%d%d%d",&r,&c,&x,&y);
        memset(num,0,sizeof(num));
        for(int i=1;i<=r;i++)
        {
            cin>>s[i];
            for(int j=0;j<s[i].size();j++)
                num[s[i][j]-'A']++;
        }
        int ans;
        sort(num,num+26,cmp);
        ans=num[0];
        int cnt=1;
        while(num[0]==num[cnt])
        {
            ans+=num[cnt];
            cnt++;
        }
        printf("Case %d: ",cases);
        printf("%d\n",ans*x+(r*c-ans)*y);
    }
    return 0;
}
