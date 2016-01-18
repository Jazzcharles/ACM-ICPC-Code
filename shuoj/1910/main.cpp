#include<iostream>
#include<cmath>
using namespace std;
typedef long long LL;
LL Pow(int a,int b){  
    return b==0?1:Pow(a,b-1)*a;  
}  
int gcd(int a,int b){
	if(!b) return a;
	else return gcd(b,a%b);
}
LL polya(int c,int s){  
    LL sum=0;  
    for(int i=1;i<=s;i++)  
        sum+=Pow(c,gcd(s,i));  
    if(s&1)  
        sum+=s*Pow(c,(s>>1)+1);  
    else{  
        for(int i=1;i<=s;i++)  
            if(i&1)  
                sum+=Pow(c,(s>>1)+1);  
            else  
                sum+=Pow(c,s>>1);  
    }  
    return sum/2/s;  
}  
int main(){
	int c,n=4;
	while(cin>>c){
		cout<<polya(c,n)<<endl;
	}
}
