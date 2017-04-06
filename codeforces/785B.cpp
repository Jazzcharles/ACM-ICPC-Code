#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6;
struct node{
	int l,r;
}a[maxn],b[maxn];

int cmp1(node x,node y){
	return x.r<y.r;
}

int cmp2(node x,node y){
	return x.l>y.l;
}
int main(){
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i].l>>a[i].r;
	}		
	int m;
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>b[i].l>>b[i].r;
	}
	sort(a,a+n,cmp1);
	sort(b,b+m,cmp2);
	int ans1=max(0,b[0].l-a[0].r);
	sort(a,a+n,cmp2);
	sort(b,b+m,cmp1);
	int ans2=max(0,a[0].l-b[0].r);
	cout<<max(ans1,ans2)<<endl;
	
	
	return 0;
}
/*
3
1 5
2 6
2 3
2
2 4
6 8

3
1 5
2 6
3 7
2
2 4
1 4




10
16 16
20 20
13 13
31 31
42 42
70 70
64 64
63 63
53 53
94 94

8
3 3
63 63
9 9
25 25
11 11
93 93
47 47
3 3
*/
