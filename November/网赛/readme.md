
###2014 ACM/ICPC Asia Regional Beijing Online

06 Frog    
已知青蛙每次至多可以跳L个距离，有N个石头，青蛙初始位置为0，目的地为M,问放置若干石头使得青蛙能到达目的地，但是跳的次数尽量多，假设青蛙足够聪明      
贪心，对当前石头，如果能一次到达就一次达到，不能一次到达的要避免用prepre那个石头直接跳过来，所以用一个变量来记录某次跳的过程的距离step,如果step加上当前要跳到石头的距离小于L，更新step加上这个距离即可，否则更新step为这个距离，ans++.当两块石头之间的距离很大时，贪心的想法是每(L+1)的距离，我都让他跳两次，具体石头放哪，还是跟已经跳的距离step有关系    


###2014 ACM/ICPC Asia Regional Xi'an Online

11 Ellipsoid     
已知椭球面方程 a*x^2+b*y^2+c*z^2+d*y*z+e*x*z+f*x*y=1,求椭球面上离原点最近的点    
模拟退火     


###2014 ACM/ICPC Asia Regional Shanghai Online    

10 Fraction    
求等比数列b*q^i中以n为前缀的数字的极限分布     
本福特定律：在b进位制中，以数n起头的数出现的机率为\log_b(n+1)-\log_b(n)    
或者枚举前20w项，求大致的概率，需要去掉前几项    

04 Contest
已知n个人做m道题正确的概率，求满足任意时刻，任意两个人已经做题数目不超过1时的最大期望    
状态dp,dp[now][s]表示当前做了now个题，且当前的n个人解决的状态，当当前状态为全1时置0       



