#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
int a[1010]={0};
int main()
{
    deque<int>q1,q2;
    while(!q1.empty())
        q1.pop_front();
    while(!q2.empty())
        q2.pop_front();
    char s[1010];
    scanf("%s",s);
    int l=strlen(s);
    int tag=1;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='.')
            tag=0;
        else if(s[i]-'0'>=0&&s[i]-'9'<=0)
        {
            if(tag)
                q1.push_back(s[i]-'0');
            else
                q2.push_back(s[i]-'0');
        }
    }
    tag=0;
    if(q2.front()<5)
        tag=1;
    if(q1.back()==9)
        printf("GOTO Vasilisa.\n");
    else
    {
        if(tag)
        {
            while(!q1.empty())
            {
                printf("%d",q1.front());
                q1.pop_front();
            }
        }
        else
        {
            int cnt=0;
            while(!q1.empty())
            {
                a[++cnt]=q1.front();
                q1.pop_front();
            }
            a[cnt]++;
            for(int i=cnt;i>=1;i--)
            {
                a[i-1]+=a[i]/10;
                a[i]%=10;
            }
            if(a[0]!=0)
                printf("%d",a[0]);
            for(int i=1;i<=cnt;i++)
            {
                printf("%d",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}


/**
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    char s[1010];
    gets(s);
    int l=strlen(s);
    int i;
    for(i=0;i<l;i++)
        if(s[i]=='.')
            break;
    if(s[i-1]=='9')
        printf("GOTO Vasilisa.\n");
    else if(s[i+1]>='5')
    {
        s[i-1]++;
        for(int j=0;j<=i-1;j++)
            printf("%c",s[j]);
        printf("\n");
    }
    else
    {
        for(int j=0;j<=i-1;j++)
            printf("%c",s[j]);
        printf("\n");
    }
    return 0;

}
*/
