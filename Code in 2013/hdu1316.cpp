/*
    BigInteger + ����
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
struct BigInt
{
    string a;
    int sign;

    BigInt() {} // default constructor

    BigInt(string b){ // constructor for string
        (*this)=b;
    }

    int size(){
        return a.size();
    }

    BigInt inverseSign(){
        sign*=-1;
        return (*this);
    }

    BigInt normalize(int newSign){ // remove leading zero and fix sign
        for(int i=a.size()-1;i>0&&a[i]=='0';i--)
            a.erase(a.begin()+i);
        sign=(a.size()==1 &&a[0]=='0'  )?1:newSign;
        return (*this);
    }

    void operator = (string b){
        a=b[0]=='-'?b.substr(1):b;
        reverse(a.begin(),a.end());
        this->normalize(b[0]=='-'?-1:1);
    }

    bool operator < (const BigInt &b) const{
        if(sign!=b.sign)    return sign<b.sign;
        if(a.size()!=b.a.size())
            return sign==1?a.size()<b.a.size():a.size()>b.a.size();
        for(int i=a.size()-1;i>=0;i--)
            if(a[i]!=b.a[i])
                return sign==1?a[i]<b.a[i]:a[i]>b.a[i];
        return false;
    }

    bool operator == (const BigInt &b) const{
        return a==b.a && sign==b.sign ;
    }

    BigInt operator + (BigInt b){
        if(sign!=b.sign)
            return (*this)- b.inverseSign();
        BigInt c;
        for(int i=0,carry=0;i<a.size()||i<b.size()||carry;i++){
            carry+=(i<a.size()?a[i]-48:0)+(i<b.size()?b.a[i]-48:0);
            c.a+=(carry%10+48);
            carry/=10;
        }
        return c.normalize(sign);
    }

    BigInt operator - (BigInt b){
        if(sign!=b.sign)
            return (*this) + b.inverseSign();
        int s=sign;
        sign=b.sign=1;
        if((*this)<b)
            return ((b-(*this)).inverseSign()).normalize(-s);
        BigInt c;
        for(int i=0,borrow=0;i<a.size();i++){
            borrow=a[i]-borrow-(i<b.size()?b.a[i]:48);
            c.a+=borrow>=0?borrow+48:borrow+58;
            borrow=borrow>=0?0:1;
        }
        return c.normalize(s);
    }

    BigInt operator * (BigInt b){
        BigInt c("0");
        for(int i=0,k=a[i]-48;i<a.size();i++,k=a[i]-48){
            while(k--) c=c+b;
            b.a.insert(b.a.begin(),'0');
        }
        return c.normalize(sign*b.sign);
    }

    BigInt operator / (BigInt b){
        if(b.size()==1 && b.a[0]=='0')
            b.a[0]/=(b.a[0]-48);
        BigInt c("0"),d;
        for(int j=0;j<a.size();j++)
            d.a+="0";
        int dsign=sign*b.sign;
        b.sign=1;
        for(int i=a.size()-1;i>=0;i--){
            c.a.insert(c.a.begin(),'0');
            c=c+a.substr(i,1);
            while(!(c<b))
                c=c-b,d.a[i]++;
        }
        return d.normalize(dsign);
    }

    BigInt operator % (BigInt b){
        if(b.size()==1 && b.a[0]=='0')
            b.a[0]/=(b.a[0]-48);
        BigInt c("0");
        b.sign=1;
        for(int i=a.size()-1;i>=0;i--){
            c.a.insert(c.a.begin(),'0');
            c=c+a.substr(i,1);
            while(!(c<b))
                c=c-b;
        }
        return c.normalize(sign);
    }
    void Print(){
        if(sign==-1) putchar('-');
        for(int i=a.size()-1;i>=0;i--)
            putchar(a[i]);
        cout<<endl;
    }
};
vector<BigInt>v;
string one="1";
string zero="0";
int main()
{
    v.clear();
    BigInt num[3];
    num[0]=one;
    num[1]=one;
    v.push_back(num[1]);
    while(num[2].size()<=101)
    {
        num[2]=num[1]+num[0];
        v.push_back(num[2]);
        num[0]=num[1];
        num[1]=num[2];
    }
    string s1,s2;
    while(cin>>s1>>s2)
    {
        if(s1=="0"&&s2=="0")
            break;
        num[0]=s1;
        num[1]=s2;
        printf("%d\n",upper_bound(v.begin(),v.end(),num[1])-lower_bound(v.begin(),v.end(),num[0]));
    }
    return 0;
}
