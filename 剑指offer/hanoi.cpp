#include<bits/stdc++.h>
using namespace std;

void print(int a,int b){
	printf("%d --> %d\n",a,b);
}


void hanoi(int n,int a,int b,int c){
	if(n == 0) return ;
	hanoi(n-1,a,c,b);
	print(a,c);
	hanoi(n-1,b,a,c);
}

int main(){
	hanoi(3,1,2,3);
	return 0;
} 
