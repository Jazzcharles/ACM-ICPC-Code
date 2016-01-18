#include <bits/stdc++.h>
using namespace std;
#define lowbit(i) (i&(-i))
const int maxn=1e5+5;

int a[maxn],bit[maxn],n,m;
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=lowbit(i);
	}
}

int query(int n){
	int s=0;
	while(i>=0){
		s+=bit[i];
		i-=lowbit(i);
	}
	return s;
}

int main(int argc, char** argv) {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]);
	}
	while(m--){
		
		
		
	}
	return 0;
}
