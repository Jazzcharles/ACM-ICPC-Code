#include<bits/stdc++.h>
using namespace std;
int a[100][100];

int main(){
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>a[i][j];
		}
	}
	for(int k = 0 ; k <= n/2 ; k++){//Ã¶¾Ù²ãÊý 
		for(int j = k ; j < n-k; j++){
			printf("%d ",a[k][j]);
		}
		for(int i = k+1 ; i < n-k; i++){
			printf("%d ",a[i][n-k-1]);
		}
		for(int j = n-k-2 ; j >= k; j--){
			printf("%d ",a[n-k-1][j]);
		}
		for(int i = n-k-2 ; i >= k+1; i--){
			printf("%d ",a[i][k]);
		}
	}
		
	
	return 0;
}
/*
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/
