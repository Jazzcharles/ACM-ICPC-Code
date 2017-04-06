#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int lcm = a*c+b+d;
	int f = 0, ans = -1;
	for(int i = 0; a*i<=lcm ; i++){
		for(int j = 0; j*c<=lcm; j++){
			if(i*a+b==d+c*j){
				ans = i*a+b;
				f=1;
				break;
			}
		}
		if(f) break;
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
/*
20 2
9 19

2 1
16 12
*/
