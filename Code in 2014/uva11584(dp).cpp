#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define maxn 1010
int dp[maxn];
char s[maxn];
bool is_plalindrome(int i,int j)
{
    while(s[i]==s[j]&&i<=j)
        i++,j--;
    if(i>=j)
        return true;
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s", s+1);
        s[0]='.';
        int l=strlen(s)-1;
        for(int i=0;i<=l;i++)
            dp[i]=i;
        for(int i=1;i<=l;i++)
        {
            for(int j=0;i-j>=1;j++)
            {
                int k=i-j;
                if(is_plalindrome(k,i))
                    dp[i]=min(dp[k-1]+1,dp[i]);
            }
        }
        printf("%d\n",dp[l]);
    }
    return 0;
}
