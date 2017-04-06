#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+500;
ll s[maxn],Hash[maxn],tot,sum,a[maxn];
map<ll,ll> mp;
void init(ll k){
	if(k==1) {
		Hash[tot++] = 1;
		return ;
	}
	if(k==-1){
		Hash[tot++] = -1;
		Hash[tot++] = 1;
		return ;
	}
	ll tmp = k;
	Hash[tot++]=1;
	while(tmp<=1e15){
		Hash[tot++]=tmp;
		tmp*=k;
	}
}

int main(){
	ll n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0) sum+=a[i];
	}

	init(k);
	for(int i = 1 ; i <= n ; i++){
		s[i] = a[i]+s[i-1];
		//mp[s[i]]++;
	}
	ll ans = 0;
	//s[r] = Hash[j] + s[l-1] 
//	cout<<tot<<endl;
//	for(int i = 0 ; i < tot ; i++) cout<<Hash[i]<<' ';cout<<endl;
	for(int l = n ; l >= 0; l--){//从右到左枚举左区间 
		for(int j = 0; j < tot ; j++){
			ll right = Hash[j]+s[l];
			ans += mp[right];
		}
		//cout<<l<<' '<<s[l]<<' '<<ans<<endl; 
		mp[s[l]]++;
	}	
	cout<<ans<<endl; 
	return 0;
} 
/*


4 2
2 2 2 2



4 -3
3 -6 -3 12


*/
