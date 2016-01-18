#include <iostream>
using namespace std;
char a[1000];
int main(int argc, char** argv) {
	int n;
	cin>>n;
	getchar();
	while(n--){
		gets(a);
		puts(a);
		cout<<endl;
	}
	gets(a);
	for(int i=0;a[i];i++){
		if(a[i]==' ')
		 cout<<endl<<endl;
		else
		 cout<<a[i];
	}
	cout<<endl;
	return 0;
}
