/*
 matrix
˼·������˷�����Ŀ����������һ������ʽ�����뵽����Ŀ����ݣ�����һ������D = [9,8,7,6,5,4,3,2,1,0] ����ʼʱ��x<=9ʱ��F(x)=x���� ����
    B=[ a9  1  0  0  0  0  0 .... 0 ]
      [ a8  0  1  0  0  0  0 .... 0 ]
      [ a7  0  0  1  0  0  0 .... 0 ]
      [ ...    ...    ...    ...   ....   0 ]
       ...    ...    ...    ...   ....    ...
      [ a1  0  0  0  0  0  0 ...  1 ]
      [ a0  0  0  0  0  0  0      0 ]
��������Ҫ��� F��n����n>9�� ��������Ļ����� B^(n-9) * D  ����� m [1] [1] , n<9�������ֱ��д�ˡ�����
*/