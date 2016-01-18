#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a[4],b[4],c[4],i;
	scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
	scanf("%d.%d.%d.%d",&b[0],&b[1],&b[2],&b[3]);
	for(int i=0;i<4;i++){
		c[i]=a[i]&b[i];
//		cout<<c[i]<<".";
	}
	int n;
	cin>>n;
	while(n--){
		scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
//		cout<<((a[0]&b[0])==c[0])<<endl;
		if(((a[0]&b[0])==c[0]) && ((a[1]&b[1])==c[1]) && ((a[2]&b[2])==c[2]) && ((a[3]&b[3])==c[3]))
		    cout<<"INNER"<<endl;
		else
		    cout<<"OUTER"<<endl;
	}
	return 0;
}
