#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
struct node{
	ll num;
	ll k;
};

int vis[maxn+500];
int main(){
	int n,m;
	cin>>n>>m;
	node s;
	s.num=n;
	s.k=0;
	queue<node> q;
	q.push(s);
	int ans=0;
	int i=n;
	while(i<m) i<<=1,ans++;
	ans+=i-m;
	vis[n]=1;
	while(!q.empty())
	{
		node temp=q.front();
		q.pop();
		ll num=temp.num;
		ll k=temp.k;
		if(k>ans) break;
		if(num==m){
			ans=k;
			break;
		}
		if(num*2<maxn && !vis[num*2]){
			node t;
			t.num=num*2;
			t.k=k+1;
			q.push(t);
			vis[num*2]=1;
		} 
		if(num-1>=0 && !vis[num-1]){
			node t;
			t.num=num-1;
			t.k=k+1;
			q.push(t);
			vis[num-1]=1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
