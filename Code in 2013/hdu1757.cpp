/*
 matrix
思路：矩阵乘法，题目给出这样的一个递推式，联想到矩阵的快速幂，构造一个矩阵D = [9,8,7,6,5,4,3,2,1,0] （初始时，x<=9时，F(x)=x）和 矩阵
    B=[ a9  1  0  0  0  0  0 .... 0 ]
      [ a8  0  1  0  0  0  0 .... 0 ]
      [ a7  0  0  1  0  0  0 .... 0 ]
      [ ...    ...    ...    ...   ....   0 ]
       ...    ...    ...    ...   ....    ...
      [ a1  0  0  0  0  0  0 ...  1 ]
      [ a0  0  0  0  0  0  0      0 ]
对于我们要求的 F（n）（n>9） 这样构造的话就是 B^(n-9) * D  结果的 m [1] [1] , n<9的情况就直接写了。。。
*/
