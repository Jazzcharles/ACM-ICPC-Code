#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--){
		string a,b,aa="",bb="";
		getline(cin,a);
		getline(cin,b);
		for(int i=0;i<a.length();i++){
			if(a[i]!=' ')
				aa+=tolower(a[i]);
		}
		for(int i=0;i<b.length();i++){
			if(b[i]!=' ')
				bb+=tolower(b[i]);
		}
		if(aa==bb) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		getchar(); 
	}
	
	return 0;
}
