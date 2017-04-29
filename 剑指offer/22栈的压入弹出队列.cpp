#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3;
int in[maxn],n;
int out[maxn];

bool judge(){
	int p = 0,q = 0;
	stack<int> s;
	while(p<n){
		while(q<n && (s.empty() || s.top() != out[p])){
			//cout<<q<<' '<<in[q]<<endl;
			s.push(in[q]);
			q++;
		}
		cout<<s.top()<<' '<<out[p]<<endl;
		if(s.top() != out[p]) return false;
		
		s.pop();
		p++;
	}
	return true;
	
}
int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		in[i] = i + 1;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>out[i];
	}
	bool ans = judge();
	cout<<ans<<endl;
	
	
	return 0;
} 
/*
5
4 5 3 2 1

5
4 3 5 1 2
*/
