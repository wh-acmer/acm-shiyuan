/*
    water

    ��n��friend������ô��n=a+b+a*b=(a+1)*(b+1)-1;
    ͬ�� a���Ա�ʾ��a=(c+1)*(d+1)-1 b���Ա�ʾ��b=(e+1)*(f+1)-1;
    ���ص�ʽ��n���� n=(c+1)*(d+1)*(e+1)*(f+1)-1;
    ͬ�������һֱ�Ƶ�������������������1�ܹ���ʾ��2���ݳ���3���ݣ�����friend��
*/
#include <stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            printf("NO!\n");
            continue;
        }
        n++;
        while(n%2==0)
        {
            n/=2;
        }
        while(n%3==0)
        {
            n/=3;
        }
        if(n==1)
        printf("YES!\n");
        else
        printf("NO!\n");
    }
    return 0;
}
