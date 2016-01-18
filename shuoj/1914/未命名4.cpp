#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n,x=1500,y=1500;
		cin>>n;getchar();
		for(int i=1;i<=n;i++){
			string s;
			getline(cin,s);
			int z=min(x,y);
			if(s[0]=='g'){
				if(z<1700) z+=233; else z+=123;
			}
			else{
				if(z<1700) z-=123; else z-=233; 
			}
			if(x<y) x=z;else y=z; 
		}
		cout<<max(x,y)<<endl;
	}
	
	return 0;
}
