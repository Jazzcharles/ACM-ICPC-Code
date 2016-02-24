#include<iostream>
#include<cstring>
using namespace std;
int a[10][10];
int row[10][10],col[10][10],s[10];
int main(){
	int n;
	cin>>n;
	while(n--){
		int f=1;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		for(int i=1;i<=9;i++) 
			for(int j=1;j<=9;j++)
				cin>>a[i][j];
		for(int i=1;i<=9;i++)
			for(int j=1;j<=9;j++){
				row[i][a[i][j]]++;
				if(row[i][a[i][j]]==2) f=0;
			}
		for(int i=1;i<=9;i++)
			for(int j=1;j<=9;j++){
				col[a[i][j]][j]++;
				if(col[a[i][j]][j]==2) f=0;
			}	
		for(int k=1;k<=9;k+=3){
			for(int l=1;l<=9;l+=3){
				memset(s,0,sizeof(s));
				for(int i=k;i<=k+2;i++){
					for(int j=l;j<=l+2;j++){
						s[a[i][j]]++;
						if(s[a[i][j]]==2) f=0;
					}
				}
			}
		}
		if(f) cout<<"Right"<<endl;
		else cout<<"Wrong"<<endl;
	}
	
	
	return 0;
}	
