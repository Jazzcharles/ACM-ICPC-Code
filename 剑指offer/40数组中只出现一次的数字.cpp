#include<bits/stdc++.h>
using namespace std;


 
int main(){
	int n;
	cin>>n;
	int res = 0;
	int mx = 0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		res ^= (1<<x);
		mx = max(mx,x);
	}
	//cout<<mx<<' '<<res<<endl; 
	for(int i=0;i<=mx;i++){
		if(res&(1<<i)) cout<<i<<endl;
	}
	
	
	return 0;

}

/*
8
2 4 3 6 3 2 5 5
*/ 
