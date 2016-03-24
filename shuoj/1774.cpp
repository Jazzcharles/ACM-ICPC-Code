#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string a=s;
		reverse(s.begin(),s.end());
		if(s==a) cout<<"YES!"<<endl;
		else cout<<"NO!"<<endl;
	}
	return 0;
}
