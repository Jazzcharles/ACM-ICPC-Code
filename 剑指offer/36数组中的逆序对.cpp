#include<bits/stdc++.h>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn = 100;

int a[100],n;
int bit[100];

void add(int i,int x){
	while(i<=maxn){
		bit[i]+=x;
		i+=lowbit(i);
	}
}

int query(int i){
	int s = 0;
	while(i){
		s+=bit[i];
		i-=lowbit(i);
	}
	return s;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int res = 0;
	for(int i=0;i<n;i++){
		res+=i-query(a[i]);
		add(a[i],1);
	}
	cout<<res<<endl;
	
	
	
	return 0;
} 
/*
4
7 5 6 4
*/ 
