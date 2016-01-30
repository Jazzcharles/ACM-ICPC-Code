#include<iostream>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int time=0,code=0;
		while(n--){
			int p,q;
			cin>>p>>q;
			time+=q;
			if(p==2) code+=q;
		}
		if(time>24) cout<<"That's impossible!"<<endl;
		else if(code<8) cout<<"Bob feels guilty!"<<endl;
		else cout<<"It's a nice day!"<<endl;
	}
	return 0;
}
