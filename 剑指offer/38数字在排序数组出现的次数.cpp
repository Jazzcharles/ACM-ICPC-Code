#include<bits/stdc++.h>
using namespace std;

int a[100];
int n,k;

int solve(int l,int r){
	int ans = 0;
	while(l<=r){
		int mid = (l+r)>>1;
		if(a[mid]<k)
			l = mid+1;
		else
			ans = mid,r = mid-1;
	}
	return ans;
}


int solve2(int l,int r){
	int ans = 0;
	while(l<=r){
		int mid = (l+r)>>1;
		if(a[mid]<=k)
			ans = mid,l = mid+1;
		else
			r = mid-1;
	}
	return ans;	
}
int main() {
	cin>>n>>k;
	for(int i =0 ; i < n;i++){
		cin>>a[i];
	}	
	int l = 0;
	int r = n-1;
	int st = solve(l,r); 
	int ed = solve2(st,r);
	cout<<st<<' '<<ed<<endl;
	int ll = lower_bound(a,a+n,k)-a;
	int rr = upper_bound(a,a+n,k)-a;
	cout<<ll<<' '<<rr<<endl;
	
	return 0;
}
/*
8 3
1 2 3 3 3 3 4 5
*/
