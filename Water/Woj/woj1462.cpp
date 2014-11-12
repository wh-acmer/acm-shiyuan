#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    deque<int>A;
    deque<int>B;
    stack<int>C;
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        while(!A.empty())
            A.pop_front();
        while(!B.empty())
            B.pop_front();
        while(!C.empty())
            C.pop();
        int tag_a=1;
        int tag_b=1;
        for(int i=1;i<=n;i++)
            A.push_front(i);
        while(!A.empty()||!B.empty())
        {
            int cnt=x;
            int tmp;
            while(cnt--)
            {
                if(A.empty())
                    break;
                if(tag_a)
                {
                    tmp=A.front();
                    A.pop_front();
                    if(tag_b)
                        B.push_front(tmp);
                    else
                        B.push_back(tmp);
                }
                else
                {
                    tmp=A.back();
                    A.pop_back();
                    if(tag_b)
                        B.push_front(tmp);
                    else
                        B.push_back(tmp);
                }
            }
            tag_a++;
            tag_a%=2;
            cnt=y;
            while(cnt--)
            {
                if(B.empty())
                    break;
                if(tag_b)
                {
                    tmp=B.front();
                    B.pop_front();
                    C.push(tmp);
                }
                else
                {
                    tmp=B.back();
                    B.pop_back();
                    C.push(tmp);
                }
            }
            tag_b++;
            tag_b%=2;
        }
        printf("Case %d: ",cases);
        while(C.size()!=1)
        {
            printf("%d ",C.top());
            C.pop();
        }
        printf("%d\n",C.top());
    }
    return 0;
}
