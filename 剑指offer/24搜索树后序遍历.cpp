#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int a[maxn],n;

bool ok(int x){
	return x>=0 && x<n;
}
bool judge(int l,int r){
	cout<<l<<' '<<r<<endl;
	if(a==NULL || l>r) return false;
	if(l==r) return true;	
	int i = l;
	while(i<r && a[i]<a[r]) i++;
	int j = i;
	while(j<r && a[j]>a[r]) j++;
	if(j != r) return false;
	return judge(l,i-1) && judge(i,r-1);
}

int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	bool ans = judge(0,n-1);
	cout<<ans<<endl; 
	
	
	return 0;
}
/*
7
5 7 6 9 11 10 8

4
7 4 6 5
*/
