#include<bits/stdc++.h>
using namespace std;


int add(int a,int b){
	int sum = 0;
	int carry = 1;
	do{
		sum = a^b;
		carry = (a&b)<<1;
		
		cout<<sum<<' '<<carry<<endl;
		a = sum;
		b = carry;
		
	}while(carry);
	
	return a;
}
int main(){
	int a,b;
	cin>>a>>b;
	int c=add(a,b);
	cout<<c<<endl;
	return 0;
} 
/*
  1 1 0 0 
  1 1 1 1
  0 0 1 1
1 1 0 0 0
1 1 0 1 1 
*/
