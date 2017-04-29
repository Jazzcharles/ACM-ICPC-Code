#include<bits/stdc++.h>
using namespace std;
int a[100];
vector<pair<int,int> > v;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	int l = 0,r = n-1;
	while(l<r)
	{
		if(a[l]+a[r]==k) {
			//cout<<a[l]<<' '<<a[r]<<endl;
			v.push_back(make_pair(l,r));
			//break;
		} 
		else if(a[l]+a[r]<k) l++;
		else r--;
	} 
	return 0;
}
/*
6
1 2 4 7 11 15
15
*/
