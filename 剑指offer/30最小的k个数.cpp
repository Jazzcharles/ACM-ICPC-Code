#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int a[maxn],n,k;
void debug(){
	for(int i = 1;i <= n;i++) cout<<a[i]<<' ';
	cout<<endl;
}

vector<int> ans;
void qsort(int l,int r){
	if(l>r) return ;
	int mid = (l+r)>>1;
	int num = a[l];
	int i = l, j = r;
	//cout<<i<<' '<<j<<endl;
	while(i<j){
		while(i<j && num<=a[j]) j--;
		if(i<j) a[i++] = a[j];
		while(i<j && num>=a[i]) i++;
		if(i<j) a[j--] = a[i];
	}
	a[i] = num;
	//debug();
	int len = (i-l+1);
	if(len == k){
		//debug();
		for(int p = l ; p <= i ; p++){
			ans.push_back(a[p]);
		}
	} 
	else if(len > k){
		qsort(l,i-1);
	}
	else{
		for(int p = l; p <= i;p++){
			ans.push_back(a[p]);
		} 
		k-=len;
		//cout<<k<<endl;
		qsort(i+1,r);
	}
	//qsort(l,i-1);
	//qsort(i+1,r);
}

int res[10];

void solve(){
	set<int,greater<int> >s;
	for(int i=1;i<=n;i++){
		int num = a[i];
		if(s.size()<k){
			s.insert(num);
		}
		else{
			if(*s.begin()>num){
				s.erase(*s.begin());
				s.insert(num);
			}
		}
	}
	for(auto iter:s) cout<<iter<<' ';cout<<endl;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	qsort(1,n); 
	for(int i =0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	solve();
	//debug();
	return 0;
} 
/*
8 4
4 5 1 6 2 7 3 8


8 1
4 5 1 6 2 7 3 8


1 2 3 4



3 5 1 6 2 7 4 8
3 4 1 6 2 7 5 8 

*/
