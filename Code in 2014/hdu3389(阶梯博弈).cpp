// ����ҳ����ղ����ƶ��ĵ�
// �ҳ��ƶ��������ƶ���ı�ŵĹ��ɣ�ת����nim
/*
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
#define maxn 60
int st[maxn];
int main()
{
    memset(st,0,sizeof(st));
    for(int i=1;i<maxn;i++)
        for(int j=i+1;j<maxn;j++)
            if((i+j)%3==0 && ((i+j)/3)&1 )
                st[j]=1;
    printf("��������ƶ���λ��:\n");
    for(int i=1;i<maxn;i++)
        if(st[i]==0) // ��������ƶ���λ��
            cout<<i<<" ";
    puts("");
    printf("�����ƶ��ģ�\n");
    for(int i=1;i<maxn;i++)
        for(int j=i+1;j<maxn;j++)
            if((i+j)%3==0 && ((i+j)/3)&1 )
                cout<<i<<" <- "<<j<<endl;
    return 0;
}
*/
// ���ֶ�����һ�ε���1��3��4״̬�ı�Ŷ���mod6����

#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,x;
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(i%6==2 || i%6==0 || i%6==5)
                ans^=x;
        }
        printf("Case %d: ",cas);
        if(ans)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
