/*
    Operation A : c--;
    Operation B :
    if(b>=x) b-=x;
    else a--,b=b-x+w;  (1)
    End a<=c

    若(1)操作了k次 . 每步B都会减x,操作了(b+k*w)/x
        c-a+k<=(b+k*w)/x
        (c-a)*x-b=k*(w-x)
              k = ((c-a)*x-b)/(w-x);
    ans=c-a+(c-a)*x/(w-x);
*/
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main(){
    long long a,b,w,x,c;
    while(cin>>a>>b>>w>>x>>c){
        if(c<=a){
            cout<<0<<endl;
        }
        else{
            cout<<c-a+(long long)ceil(((c-a)*x-b)/(w-x+0.0))<<endl;
        }
    }
}
