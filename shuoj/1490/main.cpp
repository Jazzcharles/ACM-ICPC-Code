#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	string a,b;
	int n,ca=1;
	cin>>n;getchar();
	while(n--){
		getline(cin,a);
		getline(cin,b);
		swap(a,b);
		cout<<"Case "<<ca++<<':'<<endl;
		cout<<a<<endl<<b<<endl;	
		getchar();
	}
	return 0;
}
