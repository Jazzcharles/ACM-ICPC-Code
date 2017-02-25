#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int main(){
	ll n,k;
	cin>>n>>k;
	ll cnt=0,f=-1,flag=0;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0) {
			v.push_back(i);cnt++;
		}
		if(i*i==n) flag=1;
	}
	//cout<<cnt<<endl;
	ll j=cnt-1-flag,tot=cnt*2-flag;
	for(;j>=0;j--){
		v.push_back(n/v[j]);
	}
	if(k>tot) cout<<-1<<endl;
	else cout<<v[k-1]<<endl;
	return 0;
}
/*
866421317361600 26880

*/
