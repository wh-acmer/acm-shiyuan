#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        double ans=0;
        double tmp;
        for(int i=1;i<n;i++)
        {
            tmp=i*1.0/n*(m+n);// �ܵķֳɣ�m+n����
            // ��ȥһ�������ģ���λ��Ϊ0�� ʣ����ӽ�tmp�Ĳ�����ƶ�����
            ans+=fabs(tmp-floor(tmp+0.5));
        }
        ans/=(m+n);
        printf("%.4lf\n",ans*10000);
    }
    return 0;
}
