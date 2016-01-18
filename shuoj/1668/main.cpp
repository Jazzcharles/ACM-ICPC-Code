#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	while(cin>>n && n)
	{
		if(n==1 || n==2){
			cout<<1<<endl;continue;
		}
		else 
			cout<<(n-1)/2<<endl;
	}

	return 0;
}
