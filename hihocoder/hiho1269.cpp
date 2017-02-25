#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+500;
ll a[maxn];
ll n,Q;



bool ok(ll len){
	priority_queue<ll,vector<ll>,less<ll> > q;
	ll top=0,i=0,ans=0,ct=1;
	while(i<n){
		if(top<len) {
			q.push(a[i++]);
			top++;
		}
		else{
			ll temp=q.top();
			q.pop();
			ans+=temp*ct;
			ct++;
			top--;
		//	cout<<"ans = "<<ans<<endl;
		}
	}
	while(!q.empty()){
		ans+=q.top()*ct++;
		q.pop();
	}
	//cout<<"ans = "<<ans<<' '<<"len = "<<len<<endl;
	if(ans<=Q) return 1;
	return 0;
}
int main(){
	cin>>n>>Q;
	for(int i=0;i<n;i++) cin>>a[i];
	ll l=1,r=n,ans=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		bool check=ok(mid);
		if(check){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1; 
		//cout<<l<<' '<<r<<' '<<mid<<' '<<check<<endl;
	}
	cout<<ans<<endl;
	
	
	
	
	return 0;
} 
/*
5 38
5 3 1 2 4
*/
