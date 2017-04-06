#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int f = 0;
	for(int i = 0 ; i < m ; i++){
		int p;
		cin>>p;
		if(p==1) f = 1;
		set<int> s;
		int ff = 0;
		for(int j = 0 ; j < p ; j++){
			int x; cin>>x;
			if(s.count(-x)) ff = 1;
			s.insert(x);
			//cout<<"情况:"<<' '<<ff<<endl;
		}
		if(!ff) f = 1;
		//cout<<"情况:"<<' '<<ff<<endl;
	}
	if(f) cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
	
	
	
	return 0;
} 
/*
4 2
1 -3
4 -2 3 2 -3

5 2
5 3 -2 1 -1 5
3 -5 2 5

7 2
3 -1 6 7
7 -5 4 2 4 7 -3 4

*/
