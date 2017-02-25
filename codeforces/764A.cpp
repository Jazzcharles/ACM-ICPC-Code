#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,z;
	cin>>n>>m>>z;
	int d=n*m/__gcd(n,m);
	cout<<z/d<<endl;
	
	
	
	return 0;
}
