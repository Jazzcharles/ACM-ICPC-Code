#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	string a[3];
	int n,f=0;
	cin>>n;
	cin>>a[0]>>a[1]>>a[2];
	for(int i=0;i<3;i++){
		reverse(a[i].begin(),a[i].end());
	//	cout<<a[i]<<endl;
		for(int k=0;k<=6;k++){
			string c,d;
			for(int j=0;j<n;j++){
				c+=(a[i][j]+k>'z')?a[i][j]+k-26:a[i][j]+k;
				d+=(a[i][j]-k<'a')?a[i][j]-k+26:a[i][j]-k;
			}
			for(int l=0;l<3;l++){
				if(l!=i){
					if(c==a[l] && d==a[3-i-l]){
						//cout<<c<<' '<<d<<endl;
						cout<<a[i]<<endl;
						f=1;
						break;						
					}

				}
			}
			if(f) break;
		}
		if(f) break;
		reverse(a[i].begin(),a[i].end());
	}
	return 0;
}
