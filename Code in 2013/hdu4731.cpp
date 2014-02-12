/* ´ò±í
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int s[110];
int palindrome(int len)
{
    int ans=0,l,r;
    for(int i=0;i<len;i++)
    {
        int tmp=1;
        l=i-1,r=i+1;
        while(l>=0 && r<len && s[l]==s[r])
        {
            tmp+=2;
            l--;
            r++;
        }
        ans=max(ans,tmp);
        tmp=0;
        l=i,r=i+1;
        while(l>=0 && r<len && s[l]==s[r])
        {
            tmp+=2;
            l--;
            r++;
        }
        ans=max(ans,tmp);
    }
    return ans;
}
int mx;
vector<int>ans;
void dfs(int now,int len)
{
    if(now>len)
    {
        int tmp=palindrome(len);
        if(tmp<mx)
        {
            mx=tmp;
            ans.clear();
            for(int i=0;i<len;i++)
                ans.push_back(s[i]);
        }
        else if(tmp==mx)
        {
            bool change=false;
            for(int i=0;i<ans.size();i++)
                if(ans[i]>s[i])
                {
                    change=true;
                }
            if(change)
            {
                ans.clear();
                for(int i=0;i<len;i++)
                    ans.push_back(s[i]);
            }
        }
        return ;
    }
    s[now]=1;
    dfs(now+1,len);
    s[now]=0;
    dfs(now+1,len);
}
int main()
{
    for(int i=1;i<25;i++)
    {
        mx=10000;
        ans.clear();
        dfs(0,i);
        for(int j=0;j<i;j++)
        {
            printf("%c",ans[j]+'a');
        }
        printf("\n");
    }
    return 0;
}
*/

#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
char str[]="babbaa";
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        printf("Case #%d: ",cas);
        if(m==1)
        {
            for(int i=0;i<n;i++)
                printf("a");
            printf("\n");
        }
        else if(n<=m)
        {
            for(int i=0;i<n;i++)
                printf("%c",i+'a');
            printf("\n");
        }
        else
        {
            if(m==2)
            {
                if(n==1)
                    printf("a\n");
                else if(n==2)
                    printf("ab\n");
                else if(n==3)
                    printf("aab\n");
                else if(n==4)
                    printf("aabb\n");
                else if(n==5)
                    printf("aaaba\n");
                else if(n==6)
                    printf("aaabab\n");
                else if(n==7)
                    printf("aaababb\n");
                else if(n==8)
                    printf("aaababbb\n");
                else
                {
                    printf("aaaa");
                    for(int i=0;i<(n-4)/6;i++)
                        printf("babbaa");
                    n-=4+(n-4)/6*6;
                    for(int i=0;i<n;i++)
                        printf("%c",str[i]);
                    printf("\n");
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                    printf("%c",i%3+'a');
                printf("\n");
            }
        }
    }
    return 0;
}
