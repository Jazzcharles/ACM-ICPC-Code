#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[10];
bool cmp(int a,int b){
	return a>b;
}
int main(int argc, char** argv) {
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	sort(a,a+10,cmp);
	for(int i=0;i<10;i++){
		if(i) cout<<' ';
		cout<<a[i];
	}
	return 0;
}
