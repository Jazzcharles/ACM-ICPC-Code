#include <iostream>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
LL Pow(LL a,LL b){  
    return b==0?1:Pow(a,b-1)*a%mod;  
}  
LL gcd(LL a,LL b){
    if(!b) return a%mod;
    else return gcd(b,a%b)%mod;
}
LL polya(LL c,LL s){  
    LL sum=0;  
    for(LL i=1;i<=s;i++)  
        sum+=(Pow(c,gcd(s,i)))%mod;  
    if(s&1)  
        sum+=(s*Pow(c,(s>>1)+1))%mod;  
    else{  
        for(LL i=1;i<=s;i++)  
            if(i&1)  
                sum+=(Pow(c,(s>>1)+1))%mod;  
            else 
                sum+=(Pow(c,s>>1))%mod;  
    }  
    return (sum/2/s)%mod;  
}
int main(int argc, char** argv) {
	LL c,n=3;
	while(~scanf("%lld",&c))
	{
		printf("%lld\n",polya(c,n)%mod);
	}
	return 0;
}
