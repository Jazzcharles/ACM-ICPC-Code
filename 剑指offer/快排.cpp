#include<bits/stdc++.h>
using namespace std;


void qsort(int a[],int l,int r){
	if(r<=l) return ;
	int num = a[l];
	int i = l, j = r;
	while(i < j){
		while(i < j && a[j]>=num) j--;
		if(i < j) a[i++] = a[j];
		while(i < j && a[i]<=num) i++;
		if(i < j) a[j--] = a[i];
	}
	a[i] = num;
	qsort(a,l,i-1);
	qsort(a,i+1,r);
}
int main(){
	int a[] ={1,5,2,4,3};
	qsort(a,0,5);
	for(int i = 0 ; i < 5; i++) cout<<a[i]<<' ';cout<<endl;
	
	
	
	
	return 0;
} 
