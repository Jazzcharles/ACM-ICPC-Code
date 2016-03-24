#include<iostream>
#include<cstring> 
using namespace std;
typedef long long ll;
int a,b,k;
ll fpow(ll x,ll y){
	ll ans=1;
	ll m=y; 
	for(;m;x=(x*x%(a+b)),m>>=1){
		if(m&1) ans=(ans*x)%(a+b);
	}
	return ans%(a+b);
}
int main(){
	while(cin>>a>>b>>k)
	{
		cout<<fpow(a,k)<<' '<<fpow(b,k)<<endl;
		cout<<min(fpow(a,k+1),fpow(b,k+1))<<endl;
	}
} 
