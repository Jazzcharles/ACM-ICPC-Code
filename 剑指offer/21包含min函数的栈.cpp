#include<bits/stdc++.h>
using namespace std;

//维护一个和原stack S相同数目的stack MIN来维护S的最小值 
int main(){
	stack<int> s;
	stack<int> mi;
	int n;
	cin>>n;
	int small = -0x3f;
	for(int i = 0 ; i < n ; i++)
	{
		int x;
		cin>>x;
		small = min(x,small);
		s.push(x);
		mi.push(small);
	}	
	
	
	return 0;
} 
