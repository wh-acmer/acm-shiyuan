// Computer Transformation
// http://uva.onlinejudge.org/external/16/1647.pdf
// ´ò±í

/*
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int count(string s){
    int ans=0;
    for(int i=0;i+1<s.size();i++){
        if(s[i]=='0' && s[i+1]=='0'){
            ans++;
        }
    }
    return ans;
}
int main(){
    string s="1";
    for(int cas=1;cas<=10;cas++){
        cout<<"case "<<cas<<" ";
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                str+="10";
            }
            else{
                str+="01";
            }
        }
        s=str;
        cout<<count(s)<<endl;
    }
    return 0;
}

*/

import java.io.*;
import java.math.*;
import java.util.*;
public class Main{
	static BigInteger[]dp=new BigInteger[1010];
	public static void init() {
		dp[1]=BigInteger.ZERO;
		dp[2]=dp[3]=BigInteger.ONE;
		for(int i=4;i<1010;i++){
			dp[i]=dp[i-1].multiply(BigInteger.valueOf(2));
			if(i%2==1){
				dp[i]=dp[i].subtract(BigInteger.ONE);
			}
			else{
				dp[i]=dp[i].add(BigInteger.ONE);
			}
		}
	}
    public static void main(String args[]){
    	InputStream is = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(is);
        PrintWriter out = new PrintWriter(outputStream);

        init();
        while(in.hasNext()){
        	int n=in.nextInt();
        	out.println(dp[n]);
        }

        out.close();

    }
}
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream is) {
        reader = new BufferedReader(new InputStreamReader(is));
        tokenizer = null;
    }
    public void getToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
    public boolean hasNext() {
        try {
            getToken();
        } catch (Exception e) {
            return false;
        }
        return true;
    }
    public String next() {
        getToken();
        return tokenizer.nextToken();
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }
    public long nextLong() {
        return Long.parseLong(next());
    }
}
